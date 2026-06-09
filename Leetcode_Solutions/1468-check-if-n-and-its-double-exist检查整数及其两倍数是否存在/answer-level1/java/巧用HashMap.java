**前提设定：**
    用HashMap<Integer,Integer> map存放遍历arr时当前tempNum的<2倍值,tempNum>和<1/2倍值,tempNum>（若tempNum为偶数），注意，2*tempNum、1/2*tempNum均作为key值。
**遍历开始：**
       1. 查看map中是否存在key==tempNum的键值对，是：转2；否：转3；
       2. 返回true（表明已遍历的元素中存在tempNum*1/2或tempNum*2）；
       3. 将<tempNum*2,tempNum>添加到map，若tempNum为偶数，再将<tempNum/2,tempNum>添加到map;
       4. 遍历结束，程序仍未返回，说明不存在一个整数是另外一个整数的两倍，返回false;
**注**：
    - 此解中map中的value无关紧要，也可存放当前遍历元素的索引值；
    - 进阶：若题目改为：返回所有构成2倍关系的数组元素的索引对，或元素对，即可直接将上述方法中map的value改为index，返回值改为<i,map.get(tempNum)> 或 <arr[i],arr[map.get(tempNum)]>;

```
class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int tempInt : arr){
            //Integer tempRst = map.get(tempInt);
            if(map.keySet().contains(tempInt)){
                return true;
            }else{
                map.put(tempInt*2,tempInt);
                if(tempInt%2 == 0){
                    map.put(tempInt/2,tempInt);
                }
            }
        }
        return false;
    }
}
```

    