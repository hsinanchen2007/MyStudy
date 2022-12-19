### 解题思路
考虑两种特殊情况：
1、没有反转：numbers[left]<numbers[right]
2、left=mid或left=right或者mid=right
##注意此情况应该放在while下讨论，不是像1一样单独讨论！！！！！

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size()==0) return -1;

        int a=0,b=numbers.size()-1;
        int mid=(a+b)/2;
        if (numbers[a]<numbers[b]) return numbers[a];//没有旋转的情况

        //if(numbers[a]==numbers[b] ||numbers[a]==numbers[mid] ||numbers[b]==numbers[mid]) return order_search(numbers);


        //二分法
        while((a+1)!=b)
        {
            if(numbers[mid]>numbers[a])
                {a=mid;mid=(a+b)/2;}
            else if(numbers[mid]<numbers[b])
                {b=mid;mid=(a+b)/2;}
            else if(numbers[a]==numbers[b] ||numbers[a]==numbers[mid] ||numbers[b]==numbers[mid]) return order_search(numbers);
        }
        return numbers[b];
    }
    int order_search(vector<int>& numbers){               //暴力查找，当数组初始left，right，mid值一样时的特例使用[3,3,1,3]
        int min = INT_MAX;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[i] < min) min = numbers[i];
        }
        return min;
    }

    
};
```