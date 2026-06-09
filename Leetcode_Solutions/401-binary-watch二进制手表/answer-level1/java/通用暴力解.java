罗列所有组合，输出合理解

class Solution {
 List<int[]> list = new ArrayList();
    List<String> strs = new ArrayList();
    public List<String> readBinaryWatch(int num) {

        int[] digital = new int[]{1,2,4,8,1,2,4,8,16,32};

        combination(digital,new int[num],0,num,0);

        for (int i = 0; i < list.size(); i++) {

            int[] split = list.get(i);
            int shi =0,fen=0;

            for (int j = 0; j < split.length; j++) {
                int a = split[j];
                if(a<4){
                    shi+=digital[a];
                }else{
                    fen+=digital[a];
                }
            }
            if(shi<12 && fen<60){
                strs.add(shi + (fen>9?":":":0")+fen);
            }
        }
        return strs;
    }

    public void combination(int[] digital,int[] arr,int len,int n,int m){
        if(len == n){
            list.add(arr.clone());
            return;
        }

        for(int i=m;i<digital.length;i++){
            arr[len] = i;
            combination(digital,arr,len+1,n,i+1);
        }
    }
}