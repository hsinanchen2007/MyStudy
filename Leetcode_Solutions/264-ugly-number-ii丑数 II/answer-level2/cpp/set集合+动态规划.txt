### 解题思路
本题以1作为母体存入集合，考虑集合内元素向2，3，5这三个方向的扩展，选择每次扩展最小的存入，然后让这个方向的指针前进一步，因为可能有重复，所以使用了set直接去重。
但是遇到1个问题， set<int> p; p.end()应该是迭代器表示下集合最后一个元素的下面一个位置，但是本题*p.end()是集合长度，且p.size()会报错,使用 p.rbegin()代表最后一个元素；这是set本身的语法还是编译器问题呢？ (自己编译器.size()不会报错，且.end()也是集合长度)

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
      set<int> res={1};
      auto x=res.begin();
      auto y=res.begin();
      auto z=res.begin();
        while(res.size()<n)
        {
            int temp=min(min(*x*2,*y*3),*z*5);
            res.insert(temp); //这里很关键一定要先插入，因为迭代器要走向下一个，不先插入，他就走不了，但是用数组的话没事。
            if(*x*2==temp) {
                x++;
      //          cout<<"x="<<*x<<endl;
            }
            if(*y*3==temp){
                y++;
         //          cout<<"y="<<*y<<endl;
            }
            if(*z*5==temp){
                z++;
           //     cout<<"z="<<*z<<endl;
            }
          //  cout<<temp<<" ";
        }
        if(n<=0) return 0;
        return *res.rbegin(); 
    }
};
```