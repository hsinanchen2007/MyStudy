    class Solution {
    private:
        unordered_map<int,int> memo;  //不加会超时哦
        int find(int s,int e){
            if(s > e)
                return 0;
            if(e == s)
                return 1;
            if(e == s+1)
                return 2;
            if(memo[e-s] != 0)  //左右相差相同时，可组成的搜索时数量相等
                return memo[e-s];
            int res = 0;  
            for(int i = s;i <= e;i++){
                int left = 0,right = 0;
                left = find(s,i-1);       //左子树
                right = find(i+1,e);      //右子树
                if(left != 0 && right != 0)
                    res += left*right;
                else
                    res += (left == 0) ? right:left;
            }
            memo[e-s] = res;//保存当前的结果
            return res;
        }
    public:
        int numTrees(int n) {
            if(n <= 1)
                return n;
            
            return find(1,n);
        }
    };