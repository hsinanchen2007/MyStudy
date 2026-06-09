我的思路是用String，因为String本质上是一个不可边的char数组，String本身还提供了charAt方法，那就直接比较String.length/2次就行了，可以提前判断一下是不是负数，但是这种方法也是会识别负数那那种情况的，很简单。但是提交后怎么显示用了12ms。。。。
```
public boolean isPalindrome(int x) {
        String a = String.valueOf(x);
        int b = a.length();
        for(int i=0;i<b/2;i++) {
        	if(a.charAt(i)==a.charAt(b-1-i)) {
        		continue;
        	}else {
        		return false;
        	}
        }
        return true;
    }
```

