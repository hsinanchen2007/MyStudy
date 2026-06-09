参考官方题解。

```php
class LFUCache
{
    public $minFreq;
    public $capacity;
    public $freqTable;
    public $keyTable;
    /**
     * @param Integer $capacity
     */
    function __construct($capacity)
    {
        $this->minFreq = 0;
        $this->capacity = $capacity;
        $this->freqTable = [];
        $this->keyTable = [];
    }

    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key)
    {
        // 每次访问一个已经存在的元素的时候
        // 应该先把结点从当前所属的访问次数双链表里删除，
        // 然后再添加到它「下一个访问次数」的双向链表的头部；
        if ($this->capacity <= 0) return -1;
        if (!isset($this->keyTable[$key])) return -1;
        $node = $this->keyTable[$key];
        $list = $this->freqTable[$node->freq];
        if ($node->freq == $this->minFreq && count($list) == 1) $this->minFreq++;
        $index = array_search($key, $list);
        unset($this->freqTable[$node->freq][$index]);
        if (!isset($this->freqTable[$node->freq + 1])) $this->freqTable[$node->freq + 1] = [];
        array_unshift($this->freqTable[$node->freq + 1], $key);
        $node->freq++;
        $this->keyTable[$key] = $node;
        return $node->value;
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return null
     */
    function put($key, $value)
    {
        if (isset($this->keyTable[$key])) {
            if ($this->capacity <= 0) return -1;
            $node = $this->keyTable[$key];
            $list = $this->freqTable[$node->freq];
            if ($node->freq == $this->minFreq && count($list) == 1) $this->minFreq++;
            $index = array_search($key, $list);
            unset($this->freqTable[$node->freq][$index]);
            if (!isset($this->freqTable[$node->freq + 1])) $this->freqTable[$node->freq + 1] = [];
            array_unshift($this->freqTable[$node->freq + 1], $key);
            $node->value = $value;
            $node->freq++;
            $this->keyTable[$key] = $node;
            return;
        }

        // 1、如果满了，先删除访问次数最小的的末尾结点，
        // 再删除 map 里对应的 key
        if ($this->capacity == count($this->keyTable)) {
            if (isset($this->freqTable[$this->minFreq]) && !empty($this->freqTable[$this->minFreq])) {
                $tail = array_pop($this->freqTable[$this->minFreq]);
                unset($this->keyTable[$tail]);
            }
        }

        // 2、再创建新结点放在访问次数为 1 的双向链表的前面
        $node = new LFUNode($key, $value, 1);
        $this->keyTable[$key] = $node;
        if (!isset($this->freqTable[1])) {
            $this->freqTable[1] = [];
        }
        $this->minFreq = 1;
        array_unshift($this->freqTable[1], $key);
    }
}

class LFUNode
{
    public $key;
    public $value;
    public $freq;
    public function __construct($key, $value, $freq)
    {
        $this->key = $key;
        $this->value = $value;
        $this->freq = $freq;
    }
}
```
