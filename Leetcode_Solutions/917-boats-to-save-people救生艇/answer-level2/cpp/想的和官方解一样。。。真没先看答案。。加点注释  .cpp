```
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());//升序排序
        int boats;
        vector<int>::iterator pStart = people.begin(), pEnd = people.end()-1;
        
        boats = 0;
        while (pStart <= pEnd){ //这里指针相遇 则遍历完了所有
            if (*pStart + *pEnd <= limit )//能不搭载一个 体重轻的
                pStart ++;//能 这个人被搭载了 指向下一个
            boats ++;//不论如何  这条船是要用的 所以 +1
            pEnd --;//不管能不能搭载别人 这个人都上船了（题目规定了一个人是不会超载的）
        }
        
        return boats;
    }
};
```
