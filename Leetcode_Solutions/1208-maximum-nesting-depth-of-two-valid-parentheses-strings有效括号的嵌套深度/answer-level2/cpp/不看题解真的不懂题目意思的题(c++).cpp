简单而言就是对括号string进行分类，拆分为组A和组B，每组内不需要连续，但每组独立看都必须是完成对应的括号对。同时使两组的最大深度尽可能小。
```
错误分类:不允许交错括号出现
(())
0101
允许嵌套
()(())
000110
```
只要提到括号这类成对出现的数据类型，必然使用栈的思路进行数据存放，为了使栈的深度最小，当出现多层嵌套时，一层分给A一层分给B即可，按照奇偶性分类即可。

代码
```C++
vector<int> maxDepthAfterSplit(string seq) {
    vector<int> store;//当作一个栈存放括号
    vector<int> result;
    for (auto s : seq){
        if (s=='('){
            store.push_back(0);//0代表存放一个括号
            //如果栈深是一个奇数，归类到A
            //栈深是一个偶数，归类到B
            if(store.size()%2==1)
                result.push_back(0);
            else
                result.push_back(1);
        }
        else {
            if(store.size()%2==1)
                result.push_back(0);
            else
                result.push_back(1);
            store.pop_back();
        }
    }
    return result;
}
```