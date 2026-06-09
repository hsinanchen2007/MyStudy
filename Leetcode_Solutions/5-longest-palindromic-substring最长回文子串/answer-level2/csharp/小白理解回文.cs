这一种我没有参考别人的思路 我直接草稿上面想了一下回文的概念 不停的提交 然后重写出来这个样子 只能说在进步 哈哈
一共看了几种类型的回文 还有没考虑到的情况 
比如 空字符 单字符 双字符 多字符  

"" "x" "xx" "xyx" "xyxx" 

```
public class Solution {
     /// <summary>
        /// 获取最长回文 
        /// </summary>
        public string LongestPalindrome(string s)
        {
            if(s=="")//空字符直接返回
            return "";
            char[] chars= s.ToCharArray();//字符集 //首先我将字符串解出来
            int Maxx=0;//坐标x
            int Maxy=0;//坐标y
            //循环获取当前每一个字符的最大回文
            for (int i = 0; i < chars.Length; i++)//
            {
                int x=0;//初始化x坐标
                int y=0;    //初始化y坐标
                int len = 1; //当前圆心 点位 反正就是一个概念
                int curr = i; //回文波段
                int level=0;//默认状态 无状态 1 相邻回文 2对称回文 回文的两种情况 xxxfxxxx xxxx 我可以用对称回文 也可以组成同类回文
                while (returnChar(curr,len,chars,ref level,ref x,ref y))//循环递进波段
                {
                    len++;
                }
                if((y-x)>(Maxy-Maxx)){//这儿记录坐标哦 如果大于存储的坐标 就替换
                    Maxy=y;
                    Maxx=x;
                }
            }
            return  s.Substring(Maxx,(Maxy-Maxx)+1);
        }
         public bool returnChar(int curr, int index,char[] charlist,ref int level,ref int x,ref int y)
        {
            bool xStatus=false; //x 相近
            bool yStatus=false; //y 对称
            //对称要比相近下标小一位 aba 组成对称 aa 组成相近  有可能同时满足 aaa 所以我要判断本组循环中是否满足 一种或两种


            if ((level==0 ||level==1) && (curr - index+1)>-1 && curr + index<charlist.Length &&  charlist[(curr - index+1)] == charlist[(curr + index)])
            {  
                 x=curr - index+1;
                 y=curr + index;
                 xStatus=true;

            }
            if ((level==0 ||level==2) &&  (curr - index)>-1 && curr + index<charlist.Length &&  charlist[(curr - index)] == charlist[(curr + index)])
            {
                x=curr - index;
                y=curr + index;
                yStatus=true;
            }
            //传递
            if(xStatus&&yStatus){
                level =0;
            }
            else if(xStatus){
                level=1; 
            }else if(yStatus){
                level=2;
            }else{
            return false;
            }
            return true;
        }
 }
```
