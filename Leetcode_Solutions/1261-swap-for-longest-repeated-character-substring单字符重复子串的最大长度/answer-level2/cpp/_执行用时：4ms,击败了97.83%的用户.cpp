代码有些乱
最终的字符串是无非这么几种情况：AbA、ABA，关键是区分这两种情况，前一种情况的pre和next都非0，后一种情况的pre非0，next=0,对于AbAcA这类字符串，在遍历过程中需要重用计算结果，同时改变遍历的位置，所以在结构体中引入了npos记录上一个next结束的下一位置

class Solution {
public:
    typedef struct REPOP{
        int pre;//前一部分的值
        int next;//后一部分的值
        int mark;//标记连续字符在几个位置出现
        int npos;//记录上一次计算next的位置，方便重用数据
        int max;//最大值更新
    }RNode,*RPoint;
    int maxRepOpt1(string text) {
        RPoint m=(RPoint) malloc(sizeof(RNode)*26);
        for(int i=0;i<26;i++) m[i]={0,0,0,0,0};
        int maxlength=0;
        int length=text.length();
        for(int i=0;i<length;){
            int pos=text[i]-'a';
            int rpre=0,rnext=0;
            if(m[pos].pre!=0 && i>m[pos].npos) m[pos].mark=1;//表示有可以替换的
            if(i>=2 && text[i] == text[i-2]){
                rpre=m[pos].next;
                i=m[pos].npos;
            }//利用上一次计算的结果
            else {
                do{
                    i++;
                    rpre+=1;
                }while(text[i]==text[i-1]);
                m[pos].mark+=1;
            }
            if(i+1 <= length && text[i+1]==text[i-1]){
                int j=i+1;
                while(text[j]==text[i-1]){
                    rnext+=1;
                    j++;
                }
                m[pos].npos=j;
                m[pos].mark+=1;
            }
            else if(m[pos].pre!=0 && m[pos].next==0) m[pos].mark+=1;//上一次为空这一次仍然为空,加权
            if(rpre+rnext>=m[pos].max) m[pos].max=rpre+rnext;
            m[pos].pre=rpre;
            m[pos].next=rnext;
        }
        for(int i=0;i<26;i++){
            if(m[i].mark>=3) m[i].mark=1;
            else m[i].mark=0;
            if(m[i].max + m[i].mark > maxlength) 
                maxlength=m[i].max+m[i].mark;
        }
        return maxlength;
    }
};