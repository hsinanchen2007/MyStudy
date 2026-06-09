
统计每种字母的个数，偶数全加入结果，奇数的话，如果是1就先不加，如果是大于等于3的奇数加入-1后的值
最后看是否有奇数值，有的话再加个1输出就行（最中间可以任意放个字符）。


int turnNumbers(char c) ;

int longestPalindrome(char * s){
    //偶数的字符1可以左右对称分布，奇数个字符的减1大于0的说明可以对称分布一部分，最后最中间可以插一个基数多余的字符
    //A-Z 65-90  a-z 97-122   ,将他们分散计数到相应数组中。
    //分别统计偶数的字符全部加入，基数的字符，将2*n+1 中2n部分全部加入，统计奇数字符种类个数，总数大于0 最后在加1个
    int capital[26]={0};   //  count 大写字母的相应数量
    int small[26]={0};    // count small numbers.

    if(s[0]=='\0') return 0;   //无字符情况

    int i=0; 
    while(s[i]!='\0')   //遍历每一个字符
    {
        int num = turnNumbers(s[i]);    // num值为字符ASCII码，便于存储到相应数组位置。
        if(num<=90)
        {
            num-=65;
            capital[num]++;             //累计相应大写字符个数
        }       //大写字母

        if(num>=97)   //小写字母
        {
            num-=97;
            small[num]++;
        }
        i++;
    }

    //统计每个字符奇偶，偶数全部加入可构造长度，基数大于1的加入其中偶数部分，也就是-1部分

    int length=0;    //  可构造的长度
    int ji=0 ;     //奇数个数字符种类

    for(int k=0;k<26;k++)
    {
        if(capital[k]%2==0)  
        {
            length+=capital[k];
        }
        if(capital[k]%2==1)     // 奇数部分统计
        {
            ji+=1;
            if (capital[k]>2)
            {
                length+=capital[k]-1;
            }
        }

        //小写部分
        if(small[k]%2==0)  
        {
            length+=small[k];
        }
        if(small[k]%2==1)     // 奇数部分统计
        {
            ji+=1;
            if (small[k]>2)
            {
                length+=small[k]-1;
            }
        }
    }

    if(ji>=1) length+=1;
    return length;


}

int turnNumbers(char c)      // 返回该字符对应ASCII码。
{
    int a =(int)c;
    return a;
}