```java   
 public String findLongestWord(String s, List<String> d) {
        List<String> resultList = new ArrayList<>();
        for (int i = 0; i < d.size(); i++) {
            int sIndex = 0;
            int dIndex = 0;
            String temp = d.get(i);
            while (dIndex < temp.length() && sIndex < s.length()) {
                //1. 如果两个字符相等，则两个指针继续移动， sIndex++，dIndex++，进行下一个字符的比较
                //2. 如果两个字符不相等，则sIndex++,然后继续判断s.charAt(sIndex)是否与d.charAt(dIndex)相等
                //   (1) 如果相等,sIndex++,dIndex++
                //   (2) 如果不相等，继续sIndex++，直到s.charAt(sIndex)==d.charAt(dIndex)，继续 sIndex++，dIndex++，否则终止，返回""
                if (temp.charAt(dIndex) == s.charAt(sIndex)) {
                    if (dIndex == temp.length() - 1) {
                        resultList.add(d.get(i));
                        break;
                    }
                    sIndex++;
                    dIndex++;
                } else {
                    sIndex++;
                }
            }
        }
        Collections.sort(resultList);
        return getResult(resultList);
    }

    private String getResult(List<String> tempList) {
        if (tempList.size() == 0) {
            return "";
        }
        int max = -1;
        int index = -1;
        for (int i = 0; i < tempList.size(); i++) {
            if (tempList.get(i).length() > max) {
                index = i;
                max = tempList.get(i).length();
            }
        }
        return tempList.get(index);
    }
```