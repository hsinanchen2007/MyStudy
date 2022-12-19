### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void reverse(char *str){
    int len;
    char temp;
    len = strlen(str);
    for (int i=0;i<len/2;i++){
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

char *num2str(int x,int flag){
    char *str,num;
    str = (char*)malloc(sizeof(char)*1000);
    if (x>=0){
        num = -1;
        while(x){
            str[++num] = x%10 + 48;
            x /= 10;
        }
        str[++num] = 0;
        reverse(str);
        if (flag){
            str[num] = '-';
            str[num+1] = '>';
            str[num+2] = 0;
        }
    }
    else{
        x = -x;
        num = 0;
        while(x){
            str[++num] = x%10 +48;
            x /= 10;
        }
        str[++num] = 0;
        reverse(str+1);
        str[0] = '-';
        if (flag){
            str[num] = '-';
            str[num+1] = '>';
            str[num+2] = 0;
        }
    }
    return str;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    if (!root){
        *returnSize = 0;
        return NULL;
    }
    char **ans;
    int top=-1;
    ans = (char**)malloc(sizeof(char*)*1000);
    void DFS(struct TreeNode *rt,char *str){
        if (!rt->left && !rt->right){
            char *temp,*terminal;
            temp = num2str(rt->val,0);
            terminal = (char*)malloc(sizeof(char)*(strlen(str)+strlen(temp)+2));
            strcpy(terminal,str);
            strcat(terminal,temp);
            free(temp);
            ans[++top] = terminal;
            return;
        }
        else{
            char *temp,*mid;
            temp = num2str(rt->val,1);
            mid = (char*)malloc(sizeof(char)*(strlen(str)+strlen(temp)+2));
            strcpy(mid,str);
            strcat(mid,temp);
            free(temp);
            if (rt->left)
                DFS(rt->left,mid);
            if (rt->right)
                DFS(rt->right,mid);
        }
    }
    DFS(root,"");
    *returnSize = top+1;
    return ans;
}
```