```java
import java.util.Arrays;
import java.util.Comparator;
class Loc{
    private int i;
    private int j;
    private int length;
    Loc(int i,int j,int length){
        this.i=i;
        this.j=j;
        this.length=length;
    }
    public int get_length(){
        return this.length;
    }
    public int get_i(){
        return this.i;
    }
    public int get_j(){
        return this.j;
    }
}
public class Solution{
   
    public static  int[][] allCellsDistOrder(int r,int c,int r0,int c0){
        Loc[] temp=new Loc[r*c];
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int length=Math.abs(i-r0)+Math.abs(j-c0);
                temp[k]=new Loc(i,j,length);
                k++;
            }
        }
        Comparator cmp=new MyComparator();
        Arrays.sort(temp,cmp);
        int[][] result=new int[r*c][2];
        for(int i=0;i<temp.length;i++){
            result[i][0]=temp[i].get_i();
            result[i][1]=temp[i].get_j();
        }
        return result;

    }
}
class MyComparator implements Comparator<Loc>{
    public int compare(Loc loc1,Loc loc2){
        return loc1.get_length()-loc2.get_length();
    }
}```
