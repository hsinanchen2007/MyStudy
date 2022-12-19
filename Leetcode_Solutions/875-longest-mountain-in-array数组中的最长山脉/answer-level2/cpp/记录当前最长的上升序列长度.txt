
感觉下面的写法还是很易懂的，就是额外记录一个当前节点为止的上升序列长度。
```c++
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int result = 0;
        int maxl = 0;
        int max_asc = 1;
        for(int i=1;i<A.size();++i) {
            if(A[i] > A[i-1]) { //上升，山峰断开，上升序列+1
                max_asc++;
                maxl = 0;
            } else if(A[i] == A[i-1]) {
                max_asc = 1;
                maxl = 0;
            } else {
                if(maxl == 0) { //前面未形成山峰，那么如果上升序列大于1，此时可形成山峰，并且长度是上升序列+1
                    if(max_asc > 1) maxl = max_asc + 1;
                } else { //前面已经形成山峰了，延续下去，+1
                    maxl++;
                }
                result = max(result, maxl);
                max_asc = 1;
            }
        }
        return result;
    }
};
```