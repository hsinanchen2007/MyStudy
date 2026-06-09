数学法：
从目标节点开始计算父节点
对于一个数m,它的父节点的求法如下：
设：
m>=2^N 且 m<=2^(N+1)
则：
parent=2^N-1-(m-2^N)/2

class Solution {
   
      public static  List<Integer> pathInZigZagTree(int label) {

        int N = getLevel(label);
       int[] path = new int[N+1];
        int temp = label;
       for(int i = N;i>=0;i--){
           path[i] =temp;
           int begin = (int)Math.pow(2,i);
           temp=getPre(temp,begin);
       }
       return trandToList(path);





    }
    private static List<Integer> trandToList(int[] array){
        List<Integer> pathList = new ArrayList<>(array.length);
       for(int i=0;i<array.length;i++){
           pathList.add(array[i]);
       }
       return pathList;

    }
    private static int getPre(int node,int begin){
        return  begin-1-(node-begin)/2;

    }
    private static  int getLevel(int label){
        for(int i =0;i<1000;i++){
            int begin = (int)Math.pow(2,i);
            if(label>=begin && label<begin*2){
                return i;
            }

        }
        return -1;

    }
   
}

   
  
