
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};

typedef int bool ;

#define false -1
#define true 1

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {

/*printf("%d",root1->val) ; 

printf("in") ; 
printf("%d",true) ;
/
if(root1->val != root2->val) {
return false ;
}
int b1=(root1->right!=NULL)+(root1->left!=NULL) ;
//printf("%d",b1);
int b2=(root2->right!=NULL)+(root2->left!=NULL) ;
//printf("*%d",b2);
if(b1!=b2) return false ;
else {
if(b1==0) {
return true ;
}

	if(b1==1) {
		if(root1->right!=NULL&&root2->right!=NULL) {
			if(root1->right->val!=root2->right->val) {
				return false ;
			} else {
				return flipEquiv( root1->right, root2->right) ;
			}
		}
		if(root1->right!=NULL&&root2->left!=NULL) {
			if(root1->right->val!=root2->left->val) {
				return false ;
			} else {
				return flipEquiv( root1->right, root2->left) ;
			}
		}
		if(root1->left!=NULL&&root2->right!=NULL) {
			if(root1->left->val!=root2->right->val) {
				return false ;
			} else {
				return flipEquiv( root1->left, root2->right) ;
			}
		}
		if(root1->left!=NULL&&root2->left!=NULL) {
			if(root1->left->val!=root2->left->val) {
				return false ;
			} else {
				return flipEquiv( root1->left, root2->left) ;
			}
		}
	}



	if(b1==2) {

		if(root1->left->val!=root2->left->val || root1->right->val!=root2->right->val) {
			struct TreeNode *temp =root1->left;

			root1->left=root1->right ;
			root1->right=temp ;
			if(root1->left->val!=root2->left->val || root1->right->val!=root2->right->val) {
				return false ;
			}
		}

		else {
			return (flipEquiv( root1->left, root2->left)&&flipEquiv( root1->right, root2->right)  ) ;
		}

	}
}
}

main () {
/*
struct TreeNode root1 ,root2;
root1.val=2 ;
root2.val=2;
root1.left=root1.right=root2.left=root2.right=NULL ;
printf("1") ;
printf("%d",flipEquiv( &root1, &root2)) ;
printf("2") ;
*/
struct TreeNode root1 ,root2,root11,root12,root21,root22,root111,root112,root121,root122,root211,root212,root221,root222;

root1.val= 2;
root2.val=2;

root1.left=&root11;
root1.right=&root12;

root2.left=&root21;
root2.right=&root22; 

root21.val=3 ;
root22.val=1 ;


root12.val=3 ;
root11.val=1 ;


root111.left=root111.right=NULL ; 
root111.val=6; 

root112.left=root112.right=NULL ; 
root112.val=7 ; 

root121.left=root121.right=NULL ; 
root121.val=4 ;

root122.left=root122.right=NULL ; 
root122.val=5 ;

root211.left=root211.right=NULL ; 
root211.val=4; 

root212.left=root212.right=NULL ; 
root212.val=5; 

root221.left=root221.right=NULL ; 
root221.val=6;

root222.left=root222.right=NULL ; 
root222.val=7 ;

root11.left=&root111;
root11.right=&root112;

root12.left=&root121;
root12.right=&root122;

root21.left=&root211;
root21.right=&root212;

root22.left=&root221;
root22.right=&root222;



printf("%d",flipEquiv( &root1,  &root2)) ;
}

求哪位哥哥姐姐看看我错在哪里了啊
