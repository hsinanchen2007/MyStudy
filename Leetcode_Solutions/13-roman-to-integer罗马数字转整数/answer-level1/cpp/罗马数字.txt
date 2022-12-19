```
class Solution {
public:
    int romanToInt(string s) {
        // int ret=0;
        // for(int i=s.size()-1;i>=0;i--)
        // {
        //     if(s[i]=='I')
        //     {
        //         ret=ret+1;
        //     }
        //     else if(s[i]=='V')
        //     {
        //         if(s[i-1]=='I')
        //         {
        //             ret=ret+4;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+5;
        //         }
                
        //     }
        //     else if(s[i]=='X')
        //     {
        //         if(s[i-1]=='I')
        //         {
        //             ret=ret+9;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+10;
        //         }
        //     }
        //     else if(s[i]=='L')
        //     {
        //         if(s[i-1]=='X')
        //         {
        //             ret=ret+40;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+50;
        //         }
        //     }
        //     else if(s[i]=='C')
        //     {
        //         if(s[i-1]=='X')
        //         {
        //             ret=ret+90;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+100;
        //         }    
        //     }
        //     else if(s[i]=='D')
        //     {   
        //         if(s[i-1]=='C')
        //         {
        //             ret=ret+400;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+500;
        //         }
               
        //     }
        //     else if(s[i]=='M')
        //     {
        //         if(s[i-1]=='C')
        //         {
        //             ret=ret+900;
        //             i--;
        //         }
        //         else
        //         {
        //             ret=ret+1000;
        //         }
                
        //     }
        // }
        // return ret;
        //第二种方法，利用map 进行存储对应关系，上面的方法是把所有的情况用if else 展现出来，而这个方法是通过 比较前后两个值的大小，如果小于则减去本身的值，小于的话，后面的一个值在计算的时候又会加回例如 IV 遇到 1<5  则减去1，然后 遇到V的时候，加上5，这样也就是4 了
        //这种方法的时间复杂度会比第一种方法的要高，因为要通过map 的键值进行查找 相应的数字，这个是用红黑树进行实现的，复杂度是logn ，所以总的复杂度是nlogn。
        int ret=0;
        map <char,int>m;
        m.insert(pair<char, int>('I',1));
        m.insert(pair<char, int>('V',5));
        m.insert(pair<char, int>('X',10));
        m.insert(pair<char, int>('L',50));
        m.insert(pair<char, int>('C',100));
        m.insert(pair<char, int>('D',500));
        m.insert(pair<char, int>('M',1000));
        for(int i=0;i<s.size();i++)
        {
            //cout<<"m[s[i]]:"<<m[s[i]]<<endl;
            if(m[s[i]]<m[s[i+1]])
            {
                ret=ret-m[s[i]];
            }
            else
            {
                ret=ret+m[s[i]];
            }
        }
        return ret;
    }
};
```

2020.1.9 饱读诗书小码农
这是自己今天的第二道题~加油呀~
这道题自己用两种方法~
第一种，就是根据题目意思，把所有可能的结果通过if else 进行判断写出来
第二种，就是通过map先存储相应个的结果，如果当前的s[i] 比s[i+1]小，就减相应的值，这个算法虽然代码简洁，但是通过map进行实现会带有查找值的过程，所以复杂度会变的比较高

知识点：
1. map 的使用  map 记录键和值
2. 通过insert 方法进行插入值   map.insert(pair<int,string>("IV",5));
3. map["I"] 的到的是相应的值，这个包含了查找的过程，通过key 查找 value 的过程 ，通过红黑树查找方法实现 复杂度是logn 如果没有记错的话
4. 老知识点 string 的单个字符的类型是 char 类型哦~


好的进行就是这样了~明天见