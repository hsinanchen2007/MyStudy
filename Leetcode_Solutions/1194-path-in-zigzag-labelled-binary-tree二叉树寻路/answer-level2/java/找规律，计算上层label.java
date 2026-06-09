```
package dragon.likecho.com;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int floor;
        int score;
        List <Integer> list = new ArrayList<Integer>();
        List<Integer> result = new ArrayList<Integer>();
        list.add(label);
        floor = getFloor(label);
        while (floor > 1) {
            score = getScore(label, floor);
            label -= score;
            list.add(label);
            floor = getFloor(label);
        }

        for (int i = list.size()-1; i >=0; i--) {
            result.add(list.get(i));
        }
    
        return result;
    }

    public int getScore(int label, int floor) {
        int a = label - (int)Math.pow(2, floor-1);
        return a += a/2 + 1;
    }

    public int getFloor(int label) {
        int a = label / 2;
        while (Math.pow(2, a) > label) {
            a /= 2;
        }
        while (Math.pow(2, a) < label && Math.pow(2, a+1) <= label) {
            a++;
        }

        return a+1;
    }
}
```
