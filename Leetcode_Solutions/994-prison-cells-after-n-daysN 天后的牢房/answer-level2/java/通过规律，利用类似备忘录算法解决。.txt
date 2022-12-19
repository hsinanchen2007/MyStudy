1.通过观察前21天的牢房变化情况可知该变化的周期为14，比如：第15，29天的情况和第1天一样，但需要注意的是，
  哪怕该变得次数为0，则第1个和最后一个的状态为0，所以应首先将第一个和最后一个的状态置为0。
2.首先计算出前14天的状态并将其放入一个list，然后对计算的天数取余，如天数为15，则余数为1，此时只需要list.get(0)即可，
  如天数为7，则余数为7，此时只需要list.get(6)即可。
```
import java.util.ArrayList;
import java.util.List;

/**
 * 〈功能描述〉
 * @since 2020-04-02
 */
public class PrisonAfterNDays {

    public int[] prisonAfterNDays(int[] cells, int N) {
        if (N == 0) {
            cells[0] = 0;
            cells[cells.length - 1] = 0;
            return cells;
        }
        final List<int[]> res = new ArrayList<>(14);
        int[] tmp = new int[cells.length];
        for (int index = 0; index < 14; ++index) {
            tmp = getRes(cells);
            cells = tmp;
            res.add(cells);
        }
        final int index = N % 14;
        if (index == 0) {
            return res.get(13);
        }
        return res.get(index - 1);
    }

    /**
     * 〈功能描述〉
     *
     * @apiNote
     * @param cells
     * @return
     */
    private int[] getRes(int[] cells) {
        final int[] ret = new int[cells.length];
        ret[0] = 0;
        ret[cells.length - 1] = 0;
        for (int index = 1; index < cells.length - 1; ++index) {
            if (cells[index - 1] == cells[index + 1]) {
                ret[index] = 1;
            }
        }

        return ret;
    }
}
```

