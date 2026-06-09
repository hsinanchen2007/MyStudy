### 解题思路
先把边界列出来，遍历矩阵过程中把边界内的像素加进来，最后得到res。代码可能不太优雅，效率好像还行。
![upload.jpg](https://pic.leetcode-cn.com/2818fdd0ce7362e0335593514c65f66ad01ddb431bf66b026fea867e9d253714-upload.jpg)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        	vector<vector<int> > res(M.size());
			for(int i=0;i<M.size();++i)res[i].resize(M[0].size());
        	int left=0,right=M[0].size()-1,top=0,bottom=M.size()-1;
        	for(int i=0;i<M.size();++i){
        		for(int j=0;j<M[0].size();++j){
        			int num=0,tmp=0;
        			if(i-1>=top){// 上 
        				if(j-1>=left){
        					tmp+=M[i-1][j-1];
        					++num;
						}
						tmp+=M[i-1][j];
						++num;
						if(j+1<=right){
							tmp+=M[i-1][j+1];
							++num;
						}
					}
						if(j-1>=left){//中 
        					tmp+=M[i][j-1];
        					++num;
						}
						tmp+=M[i][j];
						++num;
						if(j+1<=right){
							tmp+=M[i][j+1];
							++num;
						}
					if(i+1<=bottom){// 下 
        				if(j-1>=left){
        					tmp+=M[i+1][j-1];
        					++num;
						}
						tmp+=M[i+1][j];
						++num;
						if(j+1<=right){
							tmp+=M[i+1][j+1];
							++num;
						}
					}
					res[i][j]=tmp/num;
				} 
			}
			return res;
    }
};

```