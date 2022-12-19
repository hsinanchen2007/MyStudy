愚蠢！！

### 代码

```java
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new ArrayList<>();
        String tempLow = String.valueOf(low);
        String lowFirstChar = String.valueOf(tempLow.toCharArray()[0]);
        int lowFirst = Integer.parseInt(lowFirstChar);
        int tempResult;
        StringBuffer stringBuffer = new StringBuffer(lowFirstChar);
        for (int i = 1; i < tempLow.length(); i++) {
            if ((lowFirst + i) > 9) {
                stringBuffer = new StringBuffer();
                for (int j = 0; j < tempLow.length() +1; j++) {
                    stringBuffer.append(j + 1);
                }
                break;
            } else
                stringBuffer.append(lowFirst + i);
        }
        if (stringBuffer.toString().length() > 9)
            return result;
        tempResult = Integer.valueOf(stringBuffer.toString());
        int count = 1;
        if (tempResult < low) {
            if (tempResult % 10 == 9) {
                stringBuffer = new StringBuffer();
                for (int i = 0; i < ((tempResult + "").length() + 1); i++) {
                    if (((tempResult + "").length() + 1) > 9) {
                        return result;
                    } else
                        stringBuffer.append(i + 1);

                }
                tempResult = Integer.valueOf(stringBuffer.toString());
            } else {
                for (int i = 1; i < (tempResult + "").length(); i++) {
                    count = count * 10 + 1;
                }
                tempResult += count;
            }
            if (tempResult % 10 == 0)
                return result;
            if (tempResult <= high)
                result.add(tempResult);
            else
                return result;
        } else {
            if (tempResult % 10 == 0)
                return result;
            if (tempResult <= high)
                result.add(tempResult);
            else
                return result;
            for (int i = 1; i < (tempResult + "").length(); i++) {
                count = count * 10 + 1;
            }
        }
        while (tempResult < high) {
            if (tempResult % 10 != 9) {
                tempResult += count;
                if (tempResult % 10 == 0)
                    return result;
                if (tempResult >= low && tempResult <= high)
                    result.add(tempResult);
                else
                    break;
            } else {
                count = count * 10 + 1;
                stringBuffer = new StringBuffer("1");
                for (int i = 0; i < (tempResult + "").length(); i++) {
                    stringBuffer.append(i + 1);
                }
                tempResult = Integer.valueOf(stringBuffer.toString());
                tempResult += count / 10;
                if (tempResult % 10 == 0)
                    return result;
                if (tempResult >= low && tempResult <= high)
                    result.add(tempResult);
                else
                    break;
            }
        }
        return result;
    }
}
```