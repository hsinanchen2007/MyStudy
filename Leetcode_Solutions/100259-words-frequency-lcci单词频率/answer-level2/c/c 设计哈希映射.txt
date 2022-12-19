```
/**
*key：关于键的定义策略：把字符串所有字符减去96后进行累加操作，得到结果key,即key键
*
*整体思路：设计哈希映射
*1.为了提高空间利用率，我们把空间从1开始利用，需要把字符串减去96，使得能够存入1-90000的内存中
*2.添加映射的策略是：形参是book
*   a.把当前的字符串所有字符减去96后进行累加操作，得到结果key键
*   b.利用当前累加到的结果直接让obj指针偏移key个单位，对obj[ key ]的成员freq判断：
*       i)如果freq < 0，则证明当前内存无占用情况，此时需要判断已存储的obj[ key ].str是否等word，
*         如果等于，则更新freq += 1，结束当前映射操作，否则进入ii)
*       ii)如果freq>0，证明该位置内存已被占用，我们继续偏移260个单位，key += 260，重复步骤2
*
*3.根据关键词查询策略：形参是obj，word
*   a.计算当前字符串的key值，利用key值去访问obj，看命中效果如何，同样三种情况
*       i)如果第一次去访问obj，obj[ key ].freq < 0，集合中必定不存在当前字符串，return 0
*       ii)未命中，按照映射策略偏移260，key += 260，得到新的位置
*       iii)命中，直接返回freq
*
*4关于偏移策略值260：字母一共是26种，每个单词长度在1-10之间，字符串再怎么撑死，顶多十个z，只有
*260，此时我们进入key下标，进行访问，提高命中率的同时，也降低映射建立的时间，因为strcmp是个耗时的
*操作，我们应尽可能的避免多次执行这个函数（其实可以动态调整这个映射策略的，具体可以自己尝试）
*/

typedef struct WordsFrequency{

    //the parameter of str used to save the string in book
    char * str;
    //the parameter of freq used to save the frequency of str in book
    int freq;

} WordsFrequency;

int putMap( WordsFrequency * obj , char * word ){

    int len = 0 , key = 0;

    //calculting the key of current word
    while( *( word + len ) != '\0' ){

        key += *( word + len++ ) - 96;

    }

    for( int i = 0 ; key < 90000 && obj[ key ].freq > 0 ; i++ ){

        //if current memory is not NULL, updating freq
        if( strcmp( obj[ key ].str , word ) == 0 ){

            obj[ key ].freq += 1;
            return key;

        }

        //updating key
        key += 260;

    }

    //creating a new key of hashMap
    obj[ key ].str = ( char * )malloc( sizeof( char ) * ( len + 2 ) );
    obj[ key ].freq = 1;
    strcpy( obj[ key ].str , word );

    return key;

}

WordsFrequency * wordsFrequencyCreate( char ** book , int bookSize ) {

    int count = 1;
    WordsFrequency * obj 
                = ( WordsFrequency * )malloc( sizeof( WordsFrequency ) * 90000 );

    //creating the hashMap
    for( int i = 0 ; i < bookSize ; i++ ){

        int index = putMap( obj , *( book + i ) );


    }

    return obj;

}

int wordsFrequencyGet( WordsFrequency * obj , char * word) {

    int len = 0 , key = 0;

    //calculating the key of word
    while( *( word + len ) != '\0' ){

        key += *( word + len++ ) - 96;

    }

    //searching the word according the value of key
    //if the value of current frequency smaller than zero, return 0 
    for( int i = 0 ; key < 90000 && obj[ key ].freq > 0 ; i++ ){

        if( strcmp( obj[ key ].str , word ) == 0 ){

            return obj[ key ].freq;

        }

        key += 260;

    }


    return 0;

}

void wordsFrequencyFree( WordsFrequency * obj) {

    free( obj );   

}

/**
 * Your WordsFrequency struct will be instantiated and called as such:
 * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
 * int param_1 = wordsFrequencyGet(obj, word);
 
 * wordsFrequencyFree(obj);
*/
```
