 说实话，咱已经尽可能的少写一点东西了，不明白为什么执行用时还是这么长，呆了我的笨脑瓜！！！
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len=s1.length();        
        vector<int> _compare(len);     //存储字符串每一位的比较的结果
        vector<int> _compare(len);     //存储字符串每一位的比较的结果

        int n=0;                       //计数有区别的位
        int k=0;                       //对compare内的数据的比较操作
        for(int i=0;i<len;i++){
            _compare[i]=s1[i]-s2[i];  //s1和s2对应位若是相同，记录为0；若是不同，(x,y)即为-1,(y,x)即为1
        }
        for(auto a: _compare)n+=abs(a); //统计compare数组里不为0的数据的总数
        if(n%2)return -1;               //当n为奇数，意味着两个字符串里的x或y字符总量为奇数，总不可能通过交换字符使两字符串相等\
                                        //两字符串相等要求每种字符的总量均为偶数
        for(auto a: _compare)k^=a;       //参照题给实例，实际上只有两种基本类型的交换操作，即：1.交换(x,y)and(x,y);2.交换(x,y)and                                           //(y,x)。k的存在是在对compare内的数据另一个考校，若其中为一的数据为偶数(此时为-1的数据也应    //为偶数)，那么交换就只是第一类交换,总次数即为n/2,此时k的最终结果即是0；若不为0？，此时的所有交换里边就应该是存在一个第二类交换，而每    //个二类交换是两次交换(比一类交换多一次)，即返回n/2+1
        return (k==0)?(n/2):(n/2+1);
    }
}

```
