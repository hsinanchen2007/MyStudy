比较版本号，1.0 > 0.5
然后就是细节：1..这种其实就是1.0.0  所以就要解决缺省 是0的问题
还有就是00011 其实就是11		  所以就要解决前缀0的问题
说白了就是find(‘.’,cur)，然后将这子串转换成int（不超int，也没必要这样搞你）
既然找‘.’那必然有快，有慢，甚至大家都同时找不到‘.’
所以这里细节就是：但某个已经找不到了，他应该拿0去跟另一个比较
知道有结果（有优先级嘛，左到右），或者两个都已经找不到‘.’才结束
收获：
复习了atoi（注意是char*）所以string要转换，挺巧的，
1>atoi（空串）返回0,解决了   【‘..’ 缺省默认0】的问题
2>处理前导0
```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int num1 = 0, num2 = 0;
        while(p1 < version1.size() || p2 < version2.size()){
            while(p1<version1.size()&&version1[p1]!='.'){//解析两个小数点之间的数字
                num1 = num1*10+version1[p1]-'0';
                p1++;
            }
            while(p2<version2.size()&&version2[p2]!='.'){
                num2 = num2*10 + version2[p2] - '0';
                p2++;
            }
            if(num1>num2)
                return 1;
            if(num1<num2)
                return -1;
            num1 = 0;//注意这里要置0
            num2 = 0;
            p1++;
            p2++;
        }
        return 0;
    }
};
```
第一次写的丑代码
```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        /*
        就是比大小，每级存在前导0
        存在没，就是默认0
        . 分隔
        
        有几个. 就有多少级
        假如我去除前导0，补好漏掉的0 注意.对.这样才可以
        那这样比较就strcmp
        返回谁大就知道了
        
        就是麻烦，有没有更好的方法
        可以发现得现将
        */
        int len1 = version1.size(), len2 = version2.size();
        int cur1 = 0, cur2 = 0, lc1 = 0, lc2 = 0, done1 = 0, done2 = 0;
        int num1, num2;
        cur1 = version1.find('.', 0);
        cur2 = version2.find('.', 0);
        if (cur1 == string::npos) {//找不到了，这已经是最后一个了
            cur1 = len1;
        }
        if (cur2 == string::npos) {
            cur2 = len2;
        }
        
        
        int ans = 0;//设一开始 大家相等
        while (!(done1 && done2)) { //两个1时结束
            //有一个找不到点 那必然就结束了 但不能说另外那个就一定大，可能他后面都.....默认0呢  所以我结束条件应该是全部到达最后才能判断
            //但现在就是有可能某version提前就搜完了，那后面就应该一直是0
            if (!done1)
                num1 = atoi(version1.substr(lc1, cur1 - lc1).c_str());//数字，如果有前导0，atoi会搞定，如果什么都没有比如..他能返回0  就很好！
            else 
                num1 = 0;
            
            if (!done2)
                num2 = atoi(version2.substr(lc2, cur2 - lc2).c_str());
            else
                num2 = 0;
            
            if (num1 > num2) {
                ans = 1;
                break;
            }
            else if (num1 < num2) {
                ans = -1;
                break;
            }//else 就继续0
            
            if (!done1 && cur1 == len1) {
                done1 = 1;
            }
            if (!done2 && cur2 == len2) {
                done2 = 1;
            }
            
            
            if (!done1) {
                lc1 = cur1 + 1;
            }
            if (!done2) {
                lc2 = cur2 + 1;
            }
            if (!done1)
                cur1 = version1.find('.', cur1 + 1);//找下一个 点.
            if (!done2)
                cur2 = version2.find('.', cur2 + 1);
            
            if (!done1 && cur1 == string::npos) {//找不到了，这已经是最后一个了
                cur1 = len1;
            }
            if (!done2 && cur2 == string::npos) {
                cur2 = len2;
            }
        }
        return ans;
    }
};
```


