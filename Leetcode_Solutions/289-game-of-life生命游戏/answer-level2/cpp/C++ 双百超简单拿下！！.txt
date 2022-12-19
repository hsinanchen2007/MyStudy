### 解题思路

![Snipaste_2020-04-02_13-13-46.png](https://pic.leetcode-cn.com/caa6bda8374dd141bbb6d197ce48a8fcbf53f8aebf4cd01f89bf3450164a4112-Snipaste_2020-04-02_13-13-46.png)

好激动，第一次自己写的代码双百通过！！！( •̀ ω •́ )✧

自己看到这道题的第一想法就是先声明一个大小为m*n的数组，然后遍历原数组将每个元素的下一状态保存在新数组，最后再将新数组内容复制过去最后删除新数组。但是这样的缺点就是空间复杂度大了。所以我在想能不能不用额外空间的情况下，原数组既能保存这一时刻的状态又能保存下一时刻的状态？答案是可以的！！

因为数组的元素是int类型，而反映细胞死活只需用到一位！所以我用每个元素的第0位表示原状态，第1位表示下一状态。第一次遍历完后，第二次遍历时只要将每个元素都向右移动一位就好了！！


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int count=countAround(board,m,n,i,j);
                if(board[i][j]&1==1){//原来为活细胞
                    if(count==2 || count==3)
                        board[i][j]|=2;
                }else{//原来为死细胞
                    if(count==3)
                        board[i][j]|=2;
                }
            }
        }
        //将每个元素右移一位
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                board[i][j]>>=1;
        return;
    }

    //统计周围活细胞数
    int countAround(vector<vector<int>>& board,int m,int n,int i,int j){
        int count=0;
        if(j<n-1){
            if(board[i][j+1]&1==1)//正东
                count++;
            if(i<m-1 && board[i+1][j+1]&1==1)//东南
                count++;
        }
        if(i<m-1){
            if(board[i+1][j]&1==1)//正南
                count++;
            if(j>0 && board[i+1][j-1]&1==1)//西南
                count++;
        }
        if(j>0){
            if(board[i][j-1]&1==1)//正西
                count++;
            if(i>0 && board[i-1][j-1]&1==1)//西北
                count++;
        }
        if(i>0){
            if(board[i-1][j]&1==1)//正北
                count++;
            if(j<n-1 && board[i-1][j+1]&1==1)//东北
                count++;
        }
        return count;
    }
};
```