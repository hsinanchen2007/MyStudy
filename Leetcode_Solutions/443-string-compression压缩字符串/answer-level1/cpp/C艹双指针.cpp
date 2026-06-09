关键点在于,统计某个字符重复出现的次数,为此利用两个指针 `i,j`
我们始终让`i`指向重复字符的第一个位置,`j`指向和`i`指向的字符不等的位置
`j-i`即他们之间的距离,若`>1`,则表示需要压缩
代码如下

```cpp
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        //cnt记录结果数组的长度
        int cnt=0;
        while(i<n){
            int j=i+1;
            //该循环实现找到第一个和重复字符不等的位置
            while(j<n&&chars[j]==chars[i])
                j++;
            //加入重复字符
            chars[cnt++]=chars[i];
            int dif=j-i;
            //若需要压缩,则压缩
            if(dif>1){
                //这儿用栈实现整数的位数分解,实际上可以直接用to_string方法来获得每一位的数字
                stack<char> st;
                while(dif){
                    st.push(dif%10+'0');
                    dif/=10;
                }
                while(!st.empty())
                {
                    chars[cnt++]=st.top();
                    st.pop();
                }
            }   
            //让i指向j当前的字符
            i=j;
        }
        return cnt;
    }
```