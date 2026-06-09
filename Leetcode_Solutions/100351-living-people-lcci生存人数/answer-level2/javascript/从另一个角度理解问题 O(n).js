#### 解题思路
&emsp;&emsp;题目给出的是数据是一个人的出身年和死亡年，然后让我们根据这2组数据判断那个年份的存活人数最多。如果直接从这两个数据入手确实比较麻烦。
&emsp;&emsp;我们不妨换个角度思考，如果给出的是当前年份的累计总出生人数和累计总死亡人数，那么我们只需要简单做差即可得到总存活人数。
&emsp;&emsp;通过统计我们可以得出对应年份的出生人数和死亡人数，然后将其累加便可以得到对应年份的累计总出生人数和累计总死亡人数。
#### 代码
```c++ []
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> add(101, 0), diff(101, 0);
        int max = 0, ret = -1;
        //统计对应年份的出生人数和死亡人数
        for(int i = 0; i < birth.size(); i++){
            add[birth[i] - 1900]++;
            diff[death[i] - 1900]++;
        }
        //动态规划，累加得总出生和总死亡人数
        for(int i = 1; i < add.size(); i++){
            add[i] = add[i] + add[i - 1];
            diff[i] = diff[i] + diff[i - 1];
        }
        //做差求最大值（题目指出出生年和死亡的人数都算是当年的存活人数
        //累计人数和求最大值可以合并为一个for循环
        for(int i = 0; i < add.size(); i++){
            if(i == 0 && max < add[i]){
                max = add[i];
                ret = 0;
            }
            if(i != 0 && max < add[i] - diff[i - 1]){
                max = add[i] - diff[i - 1];
                ret = i;
            }
        }
        return ret + 1900;
    }
};
```
```java []
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
        int [] add = new int[101];
        int [] diff = new int[101];
        int max = 0, ret = -1;
        for(int i = 0; i < birth.length; i++){
            add[birth[i] - 1900]++;
            diff[death[i] - 1900]++;
        }
        for(int i = 1; i < add.length; i++){
            add[i] = add[i] + add[i - 1];
            diff[i] = diff[i] + diff[i - 1];
        }
        for(int i = 0; i < add.length; i++){
            if(i == 0 && max < add[i]){
                max = add[i];
                ret = 0;
            }
            if(i != 0 && max < add[i] - diff[i - 1]){
                max = add[i] - diff[i - 1];
                ret = i;
            }
        }
        return ret + 1900;
    }
}
```
```javascript []
var maxAliveYear = function(birth, death) {
    let add = new Array(101).fill(0),
        diff = new Array(101).fill(0),
        max = 0,
        ret = -1;
    //统计对应年份的出生人数和死亡人数
    for(let i = 0; i < birth.length; i++){
        add[birth[i] - 1900]++;
        diff[death[i] - 1900]++;
    }
    //动态规划，累加得总出生和总死亡人数
    for(let i = 1; i < add.length; i++){
        add[i] = add[i] + add[i - 1];
        diff[i] = diff[i] + diff[i - 1];
    }
    //做差求最大值（题目指出出生年和死亡的人数都算是当年的存活人数）
    for(let i = 0; i < add.length; i++){
        if(i == 0 && max < add[i]){
            max = add[i];
            ret = 0;
        }
        if(i != 0 && max < add[i] - diff[i - 1]){
            max = add[i] - diff[i - 1];
            ret = i;
        }
    }
    return ret + 1900;
};
```
