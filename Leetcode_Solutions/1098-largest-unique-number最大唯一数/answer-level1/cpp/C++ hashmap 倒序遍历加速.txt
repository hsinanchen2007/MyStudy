利用C++ stl中 **map** 是自动排序的特性
在最后遍历hashmap表时，倒叙遍历，可以更快得到最大值答案，

```C++
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int> count;
        int result = -1;
        for(int i: A){
            ++count[i];
        }
        
        for(map<int, int>::reverse_iterator p=count.rbegin();  p!=count.rend(); p++){
            //cout<<p->first<<" "<<p->second<<endl;
            if(p->second == 1) {
                result = p->first;
                break;
            }
        }
        
        return result;
    }
};
```