```php
class WordsFrequency {
    /**
     * @param String[] $book
     */
    function __construct($book) {
        $this->words = [];
        foreach ($book as $value) {
            $this->words[$value] = ($this->words[$value] ?? 0) + 1;
        }
    }

    /**
     * @param String $word
     * @return Integer
     */
    function get($word) {
        return $this->words[$word] ?? 0;
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * $obj = WordsFrequency($book);
 * $ret_1 = $obj->get($word);
 */
```