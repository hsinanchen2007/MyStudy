- 这其实可以转化为根节点是n，如果n为奇数则n的子节点是n+1和n-1否则n的子节点是n/2，n的子节点也重复上面过程
- 一直到出现1，出现1时输出层数即可，注意超范围的用例就行了。
```c++
class Solution {
public:
    int integerReplacement(int n) {
        if(n==1)return 0;
        queue<long>q;
        int deep=0;
        q.push(n);
        while(!q.empty()){
            deep++;
            int n = q.size();
            for(int i=0;i<n;i++){
                long t = q.front();
                q.pop();
                if(t==1)return deep-1;
                if(t & 1){
                    q.push(t+1);
                    q.push(t-1);
                }else q.push(t>>1);
            }
        }
        return 0;
    }
};
```