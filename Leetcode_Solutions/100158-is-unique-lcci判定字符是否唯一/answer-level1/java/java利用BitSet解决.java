这道题可以使用bitmap算法，java里面有实现好了的BitSet类，比hash表节约空间
```java
    public boolean isUnique(String astr) {
        BitSet bitSet = new BitSet();
        for(int i=0;i<astr.length();i++) {
            if(bitSet.get(astr.charAt(i))) {
                return false;
            }
            bitSet.set(astr.charAt(i));
        }
        return true;
    }
```

