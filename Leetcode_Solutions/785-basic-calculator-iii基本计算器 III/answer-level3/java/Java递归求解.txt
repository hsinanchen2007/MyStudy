class Solution {
    public int calculate(String s) {
        s=s.replaceAll(" ","");
        char[] strs=s.toCharArray();
        int[] res=getCacluateResults(strs,0);
        return res[0];
    }
    //index表明的是从哪个字符索引开始计算，返回的数组只有两个数，第一个是当前计算的结果，第二个是计算到“)”///的索引
    public int[] getCacluateResults(char[] chs,int index){
        int pre=0;
        LinkedList<String> list=new LinkedList<String>();
        while(index<chs.length&&chs[index]!=')'){
            if(chs[index]>='0'&&chs[index]<='9'){
                pre=pre*10+chs[index++]-'0';
            }else if(chs[index]!='('){ //这说明遇到了+—*/
                addNum(list,pre);
                list.add(chs[index++]+"");
                pre=0;
            //下面是整个代码的核心，遇到“(”开始进行递归计算
            }else{ //遇到( ,进行递归
                int[] arr=getCacluateResults(chs,index+1);
                pre=arr[0];
                index=arr[1];
            }
        }
         addNum(list,pre);
        return new int[]{getFinalResult(list),index+1};
    }

    //如果遇到乘除符号进入这个方法中计算，计算结果添加到list双向队列中
    public void addNum(LinkedList<String> list,int num){
        if(!list.isEmpty()){
            String symbol=list.removeLast();
            if(symbol.equals("+")|| symbol.equals("-")){
                list.add(symbol);
            }else{
                String preValue=list.removeLast();
                num=symbol.equals("*")?Integer.valueOf(preValue)*num:Integer.valueOf(preValue)/num;
            }
        }   
        list.add(String.valueOf(num));
    }
    //此时list中只有加减运算，利用这个方法求得最终结果
    public int getFinalResult(LinkedList<String> list){
        boolean add=true;
        int res=0;
        while(!list.isEmpty()){
            String value=list.removeFirst();
            if(value.equals("+")){
                add=true;
            }else if(value.equals("-")){
                add=false;
            }else {
                res+=add?Integer.valueOf(value):-Integer.valueOf(value);
            }
        }
        return res;
    }
}