### 解题思路
回溯，枚举K个数选n个的操作，用位移操作表示枚举过程

### 代码
```java
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList();
        searchTime(0, 0, num, result);
        return result;
    }

    private void searchTime(int clock, int sureNum, int count, List<String> result){
        if(count==0){
            addTimeString(clock, result);
        }else{
            int canSetPos = 10 - sureNum - count+1;
            if(canSetPos>=1){
                count--;
                for(int i=1;i<=canSetPos;i++){
                    searchTime(clock|(0x00000400>>(sureNum+i)), sureNum+i, count, result);
                }
            }
        }
    }

    private void addTimeString(int clock, List<String> result){
        int hour = (clock & 0x000003c0)>>6;
        int minites = clock & 0x0000003f;
        if(hour<=11 && minites<=59){
            if(minites<10){
                result.add(hour+":0"+minites);
            }else{
                result.add(hour+":"+minites);
            }
        }
    }
}
```