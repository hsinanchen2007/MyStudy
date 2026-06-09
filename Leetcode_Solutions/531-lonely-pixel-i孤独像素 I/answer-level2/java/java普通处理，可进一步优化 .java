```
class Solution {
    public int findLonelyPixel(char[][] picture) {
        Stack<Integer> st = new Stack<>();
        int sum=0;
        //找行B个数为1的，将其列标记录入栈(优化是去除栈中相同列，剩下的列是需要二次搜索的,本次不去重)
        for(int i=0;i<picture.length;i++){
            int countB = 0;
            for(int j=0;j<picture[0].length;j++){
              if(picture[i][j]=='B' && countB==0){
                  countB++;
                  st.push(j);
              }else if(picture[i][j]=='B'){
                   st.pop();
                   break;
              }
            }
        }
       //根据栈中元素出栈，找相应列上B元素个数是否为1
       while(!st.isEmpty()){
            int colum = st.pop();
            //列上计数为1的满足条件
            int columB = 0;
            for(int i=0,j=colum;i<picture.length;i++){
                 if(picture[i][j]=='B' && columB==0){
                     columB++;
                 }else if(picture[i][j]=='B'){
                     columB++;
                     break;
                 }
            }
            if(columB ==1){
                sum++;
            }
       }
       return sum;
    }
}
```
