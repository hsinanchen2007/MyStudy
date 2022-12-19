### 解题思路
DFS 遍历的时候通过判断字符在Trie树中是否存在来提前结束，单词存在则添加到结果中

### 代码

```php
/**
 * Class TrieNode
 */
class TrieNode
{
    public $letter;
    public $children = [];
    public $word = null;

    /**
     * @param mixed $letter
     */
    public function setLetter($letter)
    {
        $this->letter = $letter;
    }

    /**
     * @param null $word
     */
    public function setWord($word)
    {
        $this->word = $word;
    }

}

/**
 * Class Trie
 */
class Trie
{
    private $root;

    /**
     * Trie constructor.
     */
    public function __construct()
    {
        $this->root = new TrieNode();
    }


    /**
     * @return TrieNode
     */
    public function getRoot()
    {
        return $this->root;
    }


    /**
     * insert word
     * @param string $word
     */
    public function insert($word)
    {
        $len = strlen($word);
        $cur = $this->getRoot();
        for ($i = 0; $i < $len; $i++) {
            if (empty($cur->children[$word[$i]])) {
                $child = new TrieNode();
                $child->setLetter($word[$i]);
                $cur->children[$word[$i]] = $child;
            }

            $cur = $cur->children[$word[$i]];
        }
        $cur->setWord($word);
    }

}

class Solution
{

    /**
     * @param String[][] $board
     * @param String[] $words
     * @return String[]
     */
    function findWords($board, $words)
    {
        $trie = new Trie();
        $result = [];

        // 将单词存到前缀树中
        foreach ($words as $word) {
            $trie->insert($word);
        }

        $this->exist($board, $trie, $result);

        return $result;
    }


    /**
     * @param String[][] $board
     * @param Trie $trie
     * @param array $result
     */
    function exist($board, $trie, array &$result)
    {

        $rows = count($board);
        $cols = count($board[0]);

        // 遍历每个节点
        for ($i = 0; $i < $rows; $i++) {
            for ($j = 0; $j < $cols; $j++) {
                $this->find($board, $i, $j, $trie->getRoot(), $result);
            }
        }
    }


    /**
     * @param array $board
     * @param $row
     * @param $col
     * @param TrieNode $trieNode
     * @param array $result
     * @return void
     */
    function find(array &$board, $row, $col, $trieNode, array &$result)
    {
        // 判断越界
        if ($row < 0 || $row >= count($board) || $col < 0 || $col >= count($board[0])) {
            return;
        }
        $char = $board[$row][$col];

        // 当前字符在前缀树中不存在 或者已访问(#表示已访问)
        if (!isset($trieNode->children[$char]) || $char === '#') {
            return;
        }

        $trieNode = $trieNode->children[$char];

        // 树节点为一个单词的结尾，则添加到结果中
        if ($trieNode->word !== null) {
            $result[] = $trieNode->word;
            $trieNode->setWord(null);
        }

        // 标记当前位置已访问
        $temp = $char;
        $board[$row][$col] = '#';

        // right
        $this->find($board, $row, $col + 1, $trieNode, $result);

        // left
        $this->find($board, $row, $col - 1, $trieNode, $result);

        // up
        $this->find($board, $row - 1, $col, $trieNode, $result);

        // down
        $this->find($board, $row + 1, $col, $trieNode, $result);

        // 还原已访问标记
        $board[$row][$col] = $temp;

    }
}
```