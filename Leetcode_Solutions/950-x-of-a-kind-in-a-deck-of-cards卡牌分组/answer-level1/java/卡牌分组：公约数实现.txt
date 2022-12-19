1.首先找到当前数组中所有元素出现的次数
2.获取到元素出现次数的集合
3.如果有元素只出现了一次那么直接返回false
4.根据辗转相除发找出公约数（辗转相除法：一除数和余数反复做除法当余数为0时取当前除数为最大公约数 gcd(a,b) = gcb(b,a%b)）
```
public static boolean hasGroupsSizeX(Integer[] deck) {
        if(deck.length<2){
            return Boolean.FALSE;
        }
        Map<Integer,Integer> map = new HashMap<>();
        for (Integer i = 0; i < deck.length; i++) {
            if(map.containsKey(deck[i])){
                map.put(deck[i],map.get(deck[i])+1);
            }else{
                map.put(deck[i],1);
            }
        }
        int size = map.values().size();
        Integer[] integers = new Integer[size];
        Integer[] objects = map.values().toArray(integers);
        int  a = objects[0];
        for (int i = 1; i < size; i++) {
            if(objects[i]>1){
                a = gcd(a,objects[i]);
            }
            if(a== 1){
                return false;
            }
        }
        return Boolean.FALSE;
    }
}
private static int gcd (int a, int b) {
    return b == 0? a: gcd(b, a % b);
}
```
