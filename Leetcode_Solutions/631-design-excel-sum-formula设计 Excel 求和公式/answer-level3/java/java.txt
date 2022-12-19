数据量很小直接,更新了每一条规则
```
import java.util.*;

public class Excel {

    private int[][] nums;
    //key为求和坐标(r,c)的(r-1)*30+c-'A' , val为规则式
    private Map<Integer,Regular> regularMap;

    class Regular {
        private Map<Integer,Integer> map;
        private int[] target;
        public Regular(int r,char c,String[] strs) {
            target = new int[]{r-1,c-'A'};
            map = new HashMap<>();
            for(String regular:strs) {
                int index = regular.indexOf(":");
                if(index>=0) {
                    int row0 = Integer.parseInt(regular.substring(1,index))-1;
                    int col0 = regular.charAt(0)-'A';
                    int row1 = Integer.parseInt(regular.substring(index+2))-1;
                    int col1 = regular.charAt(index+1)-'A';
                    for(int i = row0;i<=row1;i++) {
                        for(int j = col0;j<=col1;j++) {
                            int code = i*30+j;
                            map.put(code,map.getOrDefault(code,0)+1);
                        }
                    }
                } else {
                    int row = Integer.parseInt(regular.substring(1))-1;
                    int col = regular.charAt(0)-'A';
                    int code = (row*30)+col;
                    map.put(code,map.getOrDefault(code,0)+1);
                }
            }
            exec();
        }
        public boolean exec() {
            int sum = 0;
            for(int code: map.keySet()) {
                int row = code/30;
                int col = code%30;
                sum += (nums[row][col]*map.get(code));
            }
            int t = nums[target[0]][target[1]];
            nums[target[0]][target[1]] = sum;
            return t==sum;
        }
    }

    public Excel(int H,char W) {
        this.nums = new int[H][W-'A'+1];
        regularMap = new HashMap<>();
    }

    public void  set(int r, char c,int v) {
        int code = (r-1)*30 + c-'A';
        regularMap.remove(code);
        nums[r-1][c-'A'] = v;
        boolean ready = false;
        while (!ready) {
            ready = true;
            for (int key : regularMap.keySet()) {
                ready&=regularMap.get(key).exec();
            }
        }
    }

    public int get(int r, char c) {
        return nums[r-1][c-'A'];
    }

    public int sum(int r, char c, String[] strs) {
        int code = (r-1)*30+c-'A';
        regularMap.remove(code);
        regularMap.put(code,new Regular(r,c,strs));
        return nums[r-1][c-'A'];
    }
}

```
