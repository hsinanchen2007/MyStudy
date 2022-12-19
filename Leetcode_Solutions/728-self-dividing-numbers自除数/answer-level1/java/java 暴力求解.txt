```
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        int tmp, sigle;
        for( ; left<=right ; left++){
            tmp = left;
            while(tmp != 0){
                //存在0，或无法整除，退出循环
                if((sigle = tmp % 10) == 0 || (left % sigle != 0)){
                    break;
                } 
                tmp /= 10;
            }
            //中途退出，tmp不可能为0
            if(tmp == 0) list.add(left);
        }
        return list;
    }
}
```
