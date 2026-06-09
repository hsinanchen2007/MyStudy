![image.png](https://pic.leetcode-cn.com/5e3e196a25cb04f650249625848e6fa56699db497f117757314fabca6ec727c1-image.png)
# 历时两小时，经过七次错误的提交，终于把所有的坑踩完了。
第一眼看到这题**感觉**这题很容易
似乎遍历一次用几个bool量标记是否出现了大写字母、小写字母、数字；用一个数组记录连续出现超过三次的字符的连续出现长度。
再遍历一次把未出现的字符补上即可。
**然而**当我提交了三次都没有通过的时候，我发现了事情不是那么简单。
**首先：删除、替换、增加这几个操作，我们该优先进行哪一个操作？
其次：该如何处理连续出现超过三次的字符？
最后：字符串中可能**有多个字符连续出现了三次**（如："aaaaaaaAAAAAA6666bbbbaaaaaaABBC"），该按什么顺序处理他们？**
1. 很容易想到，增删换操作的优先级应该是与字符串的长度有关：当字符串短于6时，优先增加操作；长度大于20时，优先删除操作；长度介于6～20时，优先替换；
2. 要处理连续出现超过三次的字符，可以按第一条的顺序，在字符串中插入字符、删去字符、更改字符。显然对于增加或者修改操作，最少只需要做len/3次操作。
3. **最难**的地方在于第三条，以"aaaaaaaAAAAAA6666bbbbaaaaaaABBC"为例（需要13步），该字符串长度为31，需要删去十一个字符。我们可以按连续出现的字符讲其表示为`7 6 4 4 6`，现在需要考虑的是在删除操作的时候应该按什么顺序处理他们。
    1. 若从前往后删除：得到`2 2 2 4 6`即代表aaAA66bbbbaaaaaaABBC，若要满足题意还需进行3步，共计14步，错误。
    2. 若从后往前删除：得到`7 3 2 2 2`即代表aaaaaaaAAA66bbaaABBC，若要满足题意还需进行3步，共计14步，错误。
    3. 我们发现，当删除操作完成后需要进行替换操作，而对于连续出现的数，最少只需要len/3次替换即可。现在需要进行的删除操作步数是固定的，那么我们可以想办法让后续的替换操作尽量减少即可。按照此规律，显然应该优先删除连续出现次数接近3的倍数的字符。于是我们可以用优先队列讲其按模3后的大小排序，依次删除队头的元素。
```
struct cmp{
        bool operator()(int x,int y){
            return (x%3) > (y%3);
        }
    };
```
所有代码如下
```
class Solution {
public:
    //优先队列比较函数，将靠近三的倍数的数放在队头
    struct cmp{
        bool operator()(int x,int y){
            return (x%3) > (y%3);
        }
    };
    int strongPasswordChecker(string s) {
        //优先队列，将连续出现次数大于三的数的出现次数放入队列
        priority_queue<int,vector<int>,cmp>same;
        //标记位，记录大小写数字出现与否
        int res=0;
        bool hasDigit=false;
        bool hasLowAlpha=false;
        bool hasHigAlpha=false;
        int pre=0;
//第一步：遍历字符串，得到字符串的信息
        for(int i=0;i<s.size();i++){
            if(i!=0&&s[i]!=s[i-1]){
                if(i-pre>=3){
                    same.push(i-pre);
                }
                pre=i;
            }else{
                if(i==s.size()-1&&i-pre>=2){
                    same.push(i-pre+1);
                }
            }
            if(islower(s[i])){
                hasLowAlpha=true;
            }else if(isupper(s[i])){
                hasHigAlpha=true;
            }else if(isdigit(s[i])){
                hasDigit=true;
            }
        }
//第二步：将字符串长度调整至6～20
        if(s.size()<6){
            int num=6-s.size();
            //增加操作
            res+=num;
            //每次增加操作都可以添加一个未出现的符号
            while(num--){
                //由于长度小于6，所以最多连续出现5个一样的数，那么只需要插入一个数就可以消除连续出现的情况
                if(!same.empty()){
                    same.pop();
                }
                //更新标记位
                if(!hasHigAlpha){
                    hasHigAlpha=true;
                }else if(!hasLowAlpha){
                    hasLowAlpha=true;
                }else if(!hasDigit){
                    hasDigit=true;
                }else{
                //若所需符号全部出现的话，那么可以随意添加，直接跳出循环。
                    break;
                }
            }
        }else if(s.size()>20){
            int num=s.size()-20;
            //删除操作
            res+=num;
            //每次删除操作优先删除连续出现的数
            while(num--){
                if(!same.empty()){
                    int tmp=same.top();
                    same.pop();
                    tmp--;
                    //当连续出现的数删除一个后小于三位，可以移出队列
                    if(tmp>=3){
                        same.push(tmp);
                    }
                //当队列空时，代表没有连续出现超过三次的数，可以直接跳出循环
                }else{
                    break;
                }
            }
        }
//第三步：消去连续出现三次的数的情况以及更换字符使字符串包含全部所需字符
        //消去连续出现的字符
        while(!same.empty()){
            int num=same.top()/3;
            res+=num;
            while(num--){
                if(!hasHigAlpha){
                    hasHigAlpha=true;
                }else if(!hasLowAlpha){
                    hasLowAlpha=true;
                }else if(!hasDigit){
                    hasDigit=true;
                }else{
                    break;
                }
            }
            same.pop();
        }
        //更换字符
        if(!hasHigAlpha){
            res++;
        }
        if(!hasLowAlpha){
            res++;
        }
        if(!hasDigit){
            res++;
        }
        return res;
    }
};


```
