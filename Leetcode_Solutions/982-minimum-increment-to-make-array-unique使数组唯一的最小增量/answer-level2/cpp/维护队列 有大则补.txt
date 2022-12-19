### 解题思路
维护队列 有大则补

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int hashtable[80001]{0};
        int result=0;
        deque<int> tmp;
        for(int i=0;i<A.size();i++){
            hashtable[A[i]]++;
            if(hashtable[A[i]]>1){
                result-=A[i];
                cout<<A[i]<<endl;
                tmp.push_back(A[i]);
            }
        }       
        if(tmp.size()==0){
            return 0;
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<80000;i++){
            if(tmp.size()==0){
                break;
            }
            if(hashtable[i]==0 && i>tmp.front()){
                result+=i;
                tmp.pop_front();
            }
        }
        return result;
    }
};
```