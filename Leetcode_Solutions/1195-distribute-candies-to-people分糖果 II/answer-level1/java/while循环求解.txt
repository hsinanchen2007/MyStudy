//贴上可在编译器中运行的完整代码
```
public class distributeCandies1103_1 {
    public static void main(String[] args) {
        int result[]=distributeCandies(10,3);
        for (int ans:result) {
            System.out.println(ans);
        }
    }
    public static int[] distributeCandies(int candies,int num_people) {
        int result[]=new int[num_people];
        int num=1;  //要分的糖果数
        int ans=0;  //要分给第几个人
        while (candies>0) {
            ans%=num_people;
            if (candies>=num) {
                result[ans++]+=num;
                candies-=num;
            } else {
                result[ans++]+=candies;
                candies=0;
            }
            num++;
        }
        return result;
    }
}
```
