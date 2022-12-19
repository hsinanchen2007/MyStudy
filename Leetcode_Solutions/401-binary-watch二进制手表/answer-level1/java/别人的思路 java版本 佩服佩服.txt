```
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        for(int i = 0;i<12;i++){
            for(int j = 0;j<60;j++){
                if(countOne(i)+countOne(j)==num){
                    String temp = i+":";
                    if(j<10){
                        temp=temp+"0"+j;
                    }else{
                        temp=temp+j;
                    }
                    result.add(temp);
                }
            }
        }
        return result;
    }
    
    int countOne(int num){
        int res = 0;
        while(num!=0){
            num=num&(num-1);
            res++;
        }
        return res;
    }
}
```
