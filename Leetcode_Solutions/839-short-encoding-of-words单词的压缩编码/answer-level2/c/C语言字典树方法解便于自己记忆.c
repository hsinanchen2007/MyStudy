C语言字典树方法解
1、首先搞清楚字典树的基本概念，它是把每个字符串存放在树的一串上,先到先得的编号资源（孩子依次a,b,c,d....z）
   a：1
     b：2
       c：3
         d：4
   假如现在要再存abca，也就是父亲c要多个孩子a
   a：1
     b：2
       c：3
   a:5    d：4
2、trieP[p][c]定义为父亲p的孩子c的分配编号
   比如abcd，先存a，给trieP[0]['a'-'a'] = 1;这时父亲更改为1，也就是p=trieP[0]['a'-'a']
   再存b，trieP[1]['b'-'a'] = 2，这时父亲更改为2，也就是p=trieP[1]['b'-'a']
   再存c，trieP[2]['c'-'a'] = 3，这时父亲更改为3，也就是p=trieP[2]['c'-'a']
   再存d，trieP[3]['d'-'a'] = 4，这时父亲更改为4，也就是p=trieP[3]['d'-'a']
   a：1
     b：2
       c：3
         d：4

3、其次数组应该定义为多大呢？
   1）父亲最多有2000*7+1，2000个字符串，每个字符串长度最大为7，再加上根父亲0
   2）每个父亲最多有多少个孩子呢？26个字母，最多26；（本题都只有小写字母）
4、每个字符串倒叙“存”到数组里，说是存，其实是用（字符-‘a’）的数值hash到对应的位置，记住trieP[p][c]定义为父亲p的孩子c的分配编号，是编号
    int lenW = strlen(words[i]);
    for(int j=lenW-1;j>=0;j--){    //遍历每个字符串
        char c = words[i][j] - 'a';   
5、这里要统计是否有不同前缀的字符串出现，重复的不处理，不同的前缀则需要
   1）分配编号 trieP[p][c] = k
   2）记录flag =1；
   3）还需要把之前p位置上的记录的长度清掉，因为可能是“em”改成了“emit”，这时原来m对应编号的长度要清掉；用t对应编号的把strlen("emit")+1,这里+1是加的#的长度

6、每次遍历完1个字符串，如果flag==1，标识无法共有前缀，就把整个字符串最后1个字符对应的resultlen[p] = lenW+1；

7、最后遍历数组resultlen求和，即可得出答案；
    for(int i=0;i<k;i++){
        sum+=resultlen[i];
    }

int minimumLengthEncoding(char ** words, int wordsSize){
#define MAX_NODES (2000*7 +1)    //最多可能有2000*7个父亲，也就是所有的字符都是父亲，+1是加上0号根父亲
#define MAX_CHILDS (26)  //每个父亲，最多有26个孩子

    int trieP[MAX_NODES][MAX_CHILDS]= {0}; //triep[i][j]表示i父亲的孩子j的编号是多少（从1开始分配，先到先得）
    int resultlen[MAX_NODES] = {0};
    int k = 1;//编号
    int flag = 0;//表示无法公用前缀，在这里，我们是倒着统计的，比如单词“time”，我们是按"emit"插入的
    int p = 0;//root 节点的编号

    for(int i=0;i<wordsSize;i++){
        p=0;
        flag =0;
        int lenW = strlen(words[i]);
        for(int j=lenW-1;j>=0;j--){    //遍历每个字符串
            char c = words[i][j] - 'a';
            if(trieP[p][c] == 0) {    //无法公用前缀
                trieP[p][c] = k;
                k++;
                flag = 1;
                resultlen[p] = 0;                
            }
            p = trieP[p][c];
        }
        if(flag == 1){
            resultlen[p] = lenW+1;                      
        }
    }
    int sum = 0;
    for(int i=0;i<k;i++){
        sum+=resultlen[i];
    }
    return sum;
}