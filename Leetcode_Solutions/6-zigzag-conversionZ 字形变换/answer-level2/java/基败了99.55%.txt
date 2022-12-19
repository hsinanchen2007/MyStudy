class Solution {

    public String convert(String s, int numRows) {
        if(numRows==1)return s;
        char [] c = s.toCharArray();
        StringBuilder tmp = new StringBuilder();
        for(int i=0;i<numRows;i++){
           int j=i;
           boolean flag=true;
           while(j<=c.length-1){
                tmp.append(c[j]);
                if(i==0||i==numRows-1){
                    j=j+2*(numRows-1);
                }else{
                    if(flag){
                        j=j+2*(numRows-1-i);
                        flag=false;
                    }else{
                        j=j+2*i;
                        flag=true;
                    }
                }
           }
        }
        return tmp.toString();
    }

}