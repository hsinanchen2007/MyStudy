```
class Solution
{

    private $grid;
    private $num   = 0;
    private $queue = [];

    /**
     * @param String[][] $grid
     *
     * @return Integer
     */
    function numIslands($grid)
    {
        $this->grid = $grid;
        foreach ($this->grid as $key => $value) {
            foreach ($value as $k => $item) {
                if ($this->grid[$key][$k] == 1) {
                    $this->num++;
                    $this->dfs( $key, $k );
                }
            }
        }
        return $this->num;

    }

    function dfs($key, $k)
    {
        if (!isset( $this->grid[$key][$k] ) || $this->grid[$key][$k] != 1)
            return;
        $this->grid[$key][$k] = 2;
        $this->dfs( $key + 1, $k );
        $this->dfs( $key - 1, $k );
        $this->dfs( $key, $k + 1 );
        $this->dfs( $key, $k - 1 );
    }

    function bfs($grid)
    {
        foreach ($grid as $key => $value) {
            foreach ($value as $k => $item) {
                if ($grid[$key][$k] == 1) {
                    $this->num++;
                    $this->queue[] = [$key, $k];
                }
            }
        }
        while (!empty( $this->queue )) {
            $i = end( $this->queue )[0];
            $j = end( $this->queue )[1];
            array_pop( $this->queue );
            $grid[$i][$j] = 2;
            $arr = [
                [$i - 1, $j],
                [$i + 1, $j],
                [$i, $j - 1],
                [$i, $j + 1],
            ];
            foreach ($arr as $item) {
                $key = reset( $item );
                $k   = end( $item );
                if (!isset( $grid[$key][$k] ) || $grid[$key][$k] != 1)
                    continue;
                $grid[$key][$k] = 2;
                $this->num--;
                $this->queue[] = [$key, $k];
            }
        }
        return $this->num;
    }
}
```
