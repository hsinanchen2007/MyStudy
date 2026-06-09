### 解题思路
其他的不想多说，就想说最后一行， if(sR.charAt(0) == '0') return "0";
如果第一个是0，就全为0

### 代码

```java
class Solution {
    public String largestNumber(int[] nums) {
int nLength = nums.length;
        String[] str = new String[nLength];
        for(int i = 0 ; i < nLength; i++){
            str[i] = String.valueOf(nums[i]);
        }

        Arrays.sort(str, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1+o2);
            }
        });


        StringBuilder sb = new StringBuilder();
        for(String s:str){
            sb.append(s);
        }

        String sR = sb.toString();
        if(sR.charAt(0) == '0') return "0";
        return sR;
    }
}
```