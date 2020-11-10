#include <iostream>
#include <vector>

class Node{
public:
    int value;
    Node *left;
    Node *right;
};
class Tree{
private:
    Node* root;
    void insert(const int &value_, Node* leaf) {
        if (leaf->value > value_) {
            if (leaf->left != NULL) {
                insert(value_, leaf->left);
            } else {
                leaf->left = new Node;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
                leaf->left->value = value_;
            }
        } else {
            if (leaf->right != NULL) {
                insert(value_, leaf->right);
            } else {
                leaf->right = new Node;
                leaf->right->right = NULL;
                leaf->right->left = NULL;
                leaf->right->value = value_;
            }
        }
    }
    Node* find(const int &value,  Node* n) {
        if (value == n->value) {
            return n;
        }
        else if (value > n->value) {
            return find(value, n->right);
        }
        else if (value < n->value) {
            return find(value, n->left);
        }
    }

public:
    Tree(){
        root=NULL;
    }
    void insert_(const int &value_){
        if(root!=NULL) {
            insert(value_, root);
        }
        else{
            root=new Node;
            root->value=value_;
            root->left=NULL;
            root->right=NULL;
        }
    }
    Node* get_root()const{
        return root;
    }
    Node* find_(const int& value){
        find(value, root);
    }


};

struct w{
    int value;
    int left;
    int right;
};



int main() {
    int N=0;
    std::cin>>N;
    std::vector<w> v;
    Tree tree;
    for(int i=0; i<N; i++){
        int x=0, y=0, z=0;
        std::cin>>x>>y>>z;
        w W={x, y, z};
        v.push_back(W);
        tree.insert_(x);
    }
    for(int i=0; i<N; i++){
        int r_1=0;
        if(v[i].right!=-1) {
            r_1 = v[v[i].right].value;
        }
        else{r_1=0;}
        int l_1=0;
        if(v[i].left!=-1){
            l_1=v[v[i].left].value;
        }else{l_1=0;}
        int r_2=0;
        if(tree.find_(v[i].value)->right) {
             r_2 = tree.find_(v[i].value)->right->value;
        }else{r_2=0;}
        int l_2=0;
        if(tree.find_(v[i].value)->left){
            l_2=tree.find_(v[i].value)->left->value;
        }else{l_2=0;}
        if(r_1!=r_2 and l_1!=l_2){
            std::cout<<"NO";
            return 0;
        }
    }
    std::cout<<"YES";
    return 0;
}
