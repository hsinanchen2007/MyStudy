首先依据题意，组成的字符串所代表的整数必须可以被 3 整除，因此该整数各个位数之和也可以被 3 整除。
想要形成 3 的最大倍数，就需要尽可能保留最大的数字，去掉的数字尽可能的小。

设数组中所有数字的和为 sum，（除去没有满足条件的结果外）有以下的 3 种情况：
1. sum % 3 == 0，直接将数组中的数字从大到小拼接起来即可；
2. sum % 3 == 1，去掉一个数组中最小的 num 满足 num % 3 == 1。**假设不存在这样的num**，则去掉两个最小的 num 满足 num % 3 == 2；
3. sum % 3 == 2，操作同 sum % 3 == 1，仅仅要去除的数的要求相反。

将剩下的数字从大到小拼接起来便是最终的结果 ans。

代码如下：
```
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        List<Integer> list = new ArrayList<>();
		for(int i = 0;i < digits.length;i++) list.add(digits[i]);
        Collections.sort(list);
		int sum = 0;String ans = "";
		for(int i = digits.length - 1;i >= 0;i--) {
			sum += digits[i];
		}
		int check = sum;boolean res = false;
		if(check % 3 != 0) {
            if(check % 3 == 1) {
                boolean haveOne = false;
                for(int i = 0;i < list.size();i++) {
				    if(list.get(i) % 3 == 1) {
                        haveOne = true;res = true;
					    list.remove(i);
					    break;
                    }
				    else check = sum;
			    }
                if(haveOne == false) {
                    int count = 2;
                    for(int i = 0;i < list.size();i++) {
                        if(list.get(i) % 3 == 2) {
                            count--;
                            list.remove(i);
                            i--;
                            if(count == 0) {
                                res = true;
                                break;
                            }
                        }
                    }
                }
            }
            if(check % 3 == 2) {
                boolean haveTwo = false;
                for(int i = 0;i < list.size();i++) {
				    if(list.get(i) % 3 == 2) {
                        haveTwo = true;res = true;
					    list.remove(i);
	                    break;
                    }
				    else check = sum;
			    }
                if(haveTwo == false) {
                    int count = 2;
                    for(int i = 0;i < list.size();i++) {
                        if(list.get(i) % 3 == 1) {
                            count--;
                            list.remove(i);i--;
                            if(count == 0) {
                                res = true;
                                break;
                            }
                        }
                    }
                }
            }
		}
        if(sum % 3 == 0) res = true;
        if(res == true) {
            for(int i = list.size() - 1;i >= 0;i--) {
			    ans = ans + list.get(i);
		    }
        }
        if(ans.length() == 0) return "";
        if(ans.charAt(0) == '0') ans = "0";
        return ans;
    }
}
```
（不知道为啥把代码粘贴到这的时候就变成这个排版了，可能会看着不太舒服，请见谅）
（或者根本没人看？QWQ）