```cpp []
//方法一：常规解法
class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        list.push_back(price);
        int len = list.size();
        if (len == 1){
            ans.push_back(1);
            return ans.back();
        }
        if (list[len-1] == list[len-2]) {
            ans.push_back(ans.back()+1);
            return ans.back();
        }
        else if (list[len-1] < list[len-2]) {
            int temp = 0;
            for (int i=len-1; i>=0; i--) {
                if (list[i] > price) 
                    break;
                temp++;
            }
            ans.push_back(temp);
            return temp;
        }        
        else {
            int temp = 0;
            for (int i=len-1-(ans.back()+1); i>=0; i--) {
                if (list[i] > price) 
                    break;
                temp++;
            }
            ans.push_back(ans.back()+1+temp);
            return ans.back();
        }
    }
    
private:
    vector<int> list,
                ans;
};

```
```cpp []
//方法二：单调栈
class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        if (element.empty()){
            element.push(price);
            days.push(1);
            return 1;
        }
        else {
            int temp = 1;
            while (price >= element.top()) {
                temp += days.top();
                element.pop();
                days.pop();
                if (element.empty())
                    break;
            }
            days.push(temp);
            element.push(price);
            return temp;
        }
    }

private:
    stack<int> element, days;
};
```

