```
class Solution {

    /**
     * @param String $beginWord
     * @param String $endWord
     * @param String[] $wordList
     * @return String[][]
     */
    function findLadders($beginWord, $endWord, $wordList) {
        $ans = $paths = [];
        $wordList = array_flip($wordList);
        $paths[] = [$beginWord];
        $level = 0;
        $min_level = pow(2, 31);
        $visited = [];
        while (!empty($paths)) {
            $path = array_shift($paths);
            if (count($path) > $level) {
                foreach ($visited as $w=>$i) unset($wordList[$w]);
                $visited = [];
                if (count($path) > $min_level) break;
                $level = count($path);
            }
            $last = end($path);
            for ($i = 0; $i < strlen($last); $i++) {
                $news = $last;
                for ($k = ord('a'); $k <= ord('z'); $k++) {
                    $news[$i] = chr($k);
                    if (isset($wordList[$news])) {
                        $newpath = $path;
                        $newpath[] = $news;
                        $visited[$news] = true;
                        if ($news == $endWord) {
                            $min_level = $level;
                            $ans[] = $newpath;
                        } else {
                            $paths[] = $newpath;
                        }
                    }
                }
            }
        }
        return $ans;
    }
}
```
