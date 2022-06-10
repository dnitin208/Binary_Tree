#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define int long long 

class node{
	public:
	int data;
	node* left;
	node* right;
	
	// Constructor
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	} 
		
	
};

void inorder(node* root){
	if(root==NULL){
		return;
    }
		
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


// Q. Find the max. BST from a given BT??

// Data Structure;
struct about{
	int maxi;
	int mini;
	int size;
	bool flag;	
};

about dfs(node* root){
	if(root==NULL){
		about ans;
		ans.maxi=-1e9;
		ans.mini=1e9;
		ans.size=0;
		ans.flag=true;
		return ans;
	}
	
	about a1=dfs(root->left);
	about a2=dfs(root->right);
	
	about ans;
	
	if(a1.flag==true and a2.flag==true and a1.maxi<root->data and a2.mini>root->data){
		ans.maxi=max({a1.maxi,a2.maxi,root->data});
		ans.mini=min({a1.mini,a2.mini,root->data});
		ans.size=a1.size+a2.size+1;
		ans.flag=true;
	}
	else{
		ans.maxi=max({a1.maxi,a2.maxi,root->data});
		ans.mini=min({a1.mini,a2.mini,root->data});
		ans.size=max(a1.size,a2.size);
		ans.flag=false;
	}
	
	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	node* root = new node(5);
	root->left = new node(4);
	root->right = new node(6);
	
	preorder(root);
	
	cout<<endl;
	
	inorder(root);
	
	// if(is_sorted( ))
	
	
}
