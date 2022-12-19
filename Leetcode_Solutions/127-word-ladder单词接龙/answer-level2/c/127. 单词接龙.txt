### 解题思路
1.第一步先把所有单词放到一个无向图里；
2.从begin开始，根据链接关系，逐层遍历字典；
3.如果发现查到最后一个单词，就回正常数字；如果遍历完所有单词，都没有找到最后一个字符，就返回0；
![image.png](https://pic.leetcode-cn.com/2ae2dc8aa38aed914afa868a734efd3c7e1b450f36070d0026ae28e5c3766c58-image.png)

### 代码

```c
#define DEBUG 0
typedef struct _node_t {
    struct _node_t *next;
    int index;
    char *word;
} node_t;
typedef struct _head_t {
    node_t *next;
    int index;
    int index_pre;
    int index_next;
    char *word;
    int deep;
    int high;
    int visit;
    int num;
} head_t;
int IsConect(char *word1, char *word2)
{
    int diffNum = 0;
    for (int i = 0; word1[i] != '\0' && word2[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            diffNum++;
            //if (diffNum > 1) break;
        }
    }

    return diffNum == 1;
} 
int IsSame(char *word1, char *word2)
{
    int i = 0;
    for (i = 0; word1[i] != '\0' && word2[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            return false;
        }
    }

    if (word1[i] == word2[i]) {
        return true;
    } else {
        return false;
    }
}

int IsEmpty(head_t *head)
{
    return head->next == NULL;
}
void Push(head_t *head, int index, char *word)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->index = index;
    new_node->word = word;
    new_node->next = head->next;
    head->next = new_node;
}
void Add(head_t *head, node_t *new_node)
{
    new_node->next = head->next;
    head->next = new_node;
}
node_t *Pop(head_t *head)
{
    if (!IsEmpty(head)) {
        node_t *p_node = NULL;
        p_node = head->next;
        head->next = head->next->next;
        return p_node;
    }
    return NULL;
}
void MakeEmpty(head_t *head)
{
    node_t *p_node = NULL;
    while (!IsEmpty(head)) {
        p_node = Pop(head);
        free(p_node);
    }
}
void InitHead(head_t *head, char *word, int index)
{
    head->next = NULL;
    head->index = index;
    head->word = word;
    head->index_pre = -1;
    head->index_next = -1;
    head->deep = -1;
    head->high = -1;
    head->visit = 0;
    head->num = 0;
}

head_t *CreateHead(char * beginWord, char * endWord, char ** wordList, int wordListSize)
{
    head_t *head = (head_t *)malloc(sizeof(head_t) * (wordListSize + 2));
    if (head == NULL) return NULL;
    int isEndWord = false;
    for (int i =0; i<wordListSize; i++) {
        if (IsSame(wordList[i], endWord)) {
            isEndWord = true;
            break;
        }
    }
    if (isEndWord == false) return NULL;

    InitHead(&head[wordListSize],endWord,wordListSize);
    InitHead(&head[wordListSize + 1],beginWord,wordListSize + 1);

    for (int i = 0; i<wordListSize; i++) {
        InitHead(&head[i],wordList[i],i);
    }

    for (int i = 0; i<wordListSize; i++) {
        if (IsConect(wordList[i], beginWord)) {
            Push(&head[wordListSize + 1], i, wordList[i]);
            head[wordListSize + 1].num++;
            head[i].visit = 1;
        }
        if (IsSame(wordList[i], beginWord)) {
            head[wordListSize + 1].num++;
            head[i].visit = 1;
        }
        if (IsConect(wordList[i], endWord)) {
            Push(&head[i], wordListSize, endWord);
            head[i].num++;
            continue;
        }
        for (int j=0; j<wordListSize; j++) {
            if (i == j) continue;
            if(IsConect(wordList[i], wordList[j])) {
                Push(&head[i],j,wordList[j]);
                Push(&head[j],i,wordList[i]);
                head[i].num++;
                head[j].num++;
            }
        }
    }
    return head;
}
void PrintNodes(node_t *node, head_t *head)
{
    if (node == NULL) return;
    printf(" -> %5s/%2d/%d",node->word, node->index, head[node->index].high);
    PrintNodes(node->next,head);
}
void PrintHead(char * beginWord, char * endWord, char ** wordList, int wordListSize, head_t *head, int start)
{
    //return;
    if (DEBUG == 0) return;
    for (int i=start; i<wordListSize+2; i++) {
        //printf("%d %s :",head[i].index,head[i].word);
        printf("%5s [%d, %d, %d][%d,%d]:",head[i].word,
            head[i].index, head[i].index_pre, head[i].index_next,
            head[i].deep, head[i].high);
        PrintNodes(head[i].next,head);
        printf("\n");
    }
    printf("\n-----------------------\n");
}
int PrintResult1(head_t *head, int beginIndex, int endIndex)
{
    if (beginIndex < 0 || endIndex < 0) return 0;
    int ret = 1;
    if (beginIndex != endIndex) {
        ret += PrintResult1(head, beginIndex, head[endIndex].index_pre);
        printf(" -> %s",head[endIndex].word);
    } else {
        printf("%s",head[endIndex].word);
    }
    return ret;
}
int PrintResult2(head_t *head, int beginIndex, int endIndex)
{
    if (beginIndex < 0 || endIndex < 0) return 0;
    int ret = 1;
    if (beginIndex != endIndex) {
        printf("%s -> ",head[beginIndex].word);
        ret += PrintResult2(head, head[beginIndex].index_next, endIndex);
    } else {
        printf("%s",head[beginIndex].word);
    }
    return ret;
}
void PrintResult(head_t *head, int beginIndex, int endIndex)
{
    if (DEBUG == 0) return;
    int ret = 0;
    ret = PrintResult1(head, beginIndex, endIndex);
    printf("\n num = %d\n",ret);
    ret = PrintResult2(head, beginIndex, endIndex);
    printf("\n num = %d\n",ret);
}
int Search(head_t *head, int beginIndex, int endIndex, int lastIndex, int deep)
{
    if (beginIndex == endIndex) {
        if (deep + 1 < head[beginIndex].deep || head[beginIndex].deep < 0) {
            head[beginIndex].deep = deep + 1;
            head[beginIndex].high = 1;
            head[beginIndex].index_pre = lastIndex;
        }
        return 1;
    }
    
    int tmp = 0;
    int ret = 0;
    node_t *p_node = NULL;
    node_t *tmp_node = NULL;
    if (head[beginIndex].deep < 0 || head[beginIndex].deep > deep + 1) {                // 未访问过该节点前
        head[beginIndex].deep = deep + 1;
        head[beginIndex].index_pre = lastIndex;

        //if (head[beginIndex].high <= 0) {
            p_node = head[beginIndex].next;
            int tmp_index = -1;
            int tmp_min_high = -1;
            while (p_node  != NULL) {
                tmp = Search(head, p_node->index, endIndex, beginIndex, deep + 1);
                if (tmp > 0 && (tmp < tmp_min_high || tmp_min_high < 0)) {
                    tmp_min_high = tmp;
                    tmp_index = p_node->index;
                    //if (tmp < head[beginIndex].high || head[beginIndex].high < 0) {
                    //    head[beginIndex].high = tmp + 1;
                    //    head[beginIndex].index_next = p_node->index;
                    //}
                }
                p_node = p_node->next;
            }

            if (tmp_min_high > 0) {
                head[beginIndex].high = tmp_min_high + 1;
                head[beginIndex].index_next = tmp_index;
            } else {
                return -1;
            }
        //} 
        return head[beginIndex].high;
    }

    return head[beginIndex].high;

    //if (head[beginIndex].high > 0) {
    //    return head[beginIndex].high;
    //} else {
    //    return -1;
    //}
}

int SearchInLevev(head_t *head, int level, head_t *lastLevel, int *remain, int wordListSize)
{

    if (lastLevel == NULL) return 0;

    if(DEBUG == 1)printf("[%d]",level);
    PrintNodes(lastLevel->next, head);
    if(DEBUG == 1)printf("\n");

    head_t *newLevel = (head_t *)malloc(sizeof(head_t));
    if (newLevel == NULL) return 0;
    InitHead(newLevel, NULL,level + 1);

    node_t *p_lastNode = NULL;
    node_t *p_node = NULL;
    p_lastNode = lastLevel->next;

    if (p_lastNode == NULL) return 0;
    int index = 0;
    while (p_lastNode != NULL) {
        index = p_lastNode->index;

        //while ((p_node = Pop(head[index]) != NULL) {
        for (p_node = Pop(&head[index]); p_node != NULL; p_node = Pop(&head[index])) {
            if (head[p_node->index].visit == 1) {
                continue;
            }
            if (p_node->index == wordListSize)
            {
                return level + 1;
            }
            Add(newLevel, p_node);
            head[p_node->index].visit = 1;
            if (++(*remain) > wordListSize)
            {
                printf("visit all the word, remain = %d, wordListSize = %d\n",*remain, wordListSize);
                return 0;
            }
        }
        //PrintNodes(newLevel->next, head);
        //printf("\n");
        p_lastNode = p_lastNode->next;
    }

    int ret = SearchInLevev(head, level + 1, newLevel, remain, wordListSize);
    MakeEmpty(newLevel);
    free(newLevel);

    return ret;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 1) return 0;

    if (IsConect(beginWord, endWord)) {
        return 2;
    }
    int ret = 0;

    // 1.扫描字典，建立转换关系，优先建立到结束字符的关系；
    head_t *head = CreateHead(beginWord, endWord, wordList, wordListSize);
    if (head == NULL) return 0;
    PrintHead(beginWord, endWord, wordList, wordListSize, head, 0/*wordListSize*/);
    // 2.逐层搜索，搜索所有可能，逐步缩短起点到终点的长度；
    //Search(head, wordListSize + 1, wordListSize, -1, 0);

    int remain = head[wordListSize + 1].num;
    
    ret = SearchInLevev(head, 1, &head[wordListSize + 1], &remain, wordListSize);
    if (ret) return ret + 1;
    return 0;

    PrintHead(beginWord, endWord, wordList, wordListSize, head, 0/*wordListSize*/);
//return 0;
    PrintResult(head, wordListSize + 1, wordListSize);
    // 3.遍历链表，统计长度；

    if (head[wordListSize+ 1].high > 0) {
        ret = head[wordListSize + 1].high;
    }
    for (int i=0; i < wordListSize+2; i++) {
        MakeEmpty(&head[i]);
    }
    free(head);
    return ret;
}

/* test case
"hit"
"cog"
["hot","dot","dog","lot","log","cog"]

"hit"
"cog"
["hod","dot","dog","lot","log","cog"]

"hit"
"hid"
[]

"hit"
"hod"
["hot"]

"hit"
"cog"
["hot","dot","dog","lot","log"]

"red"
"tax"
["ted","tex","red","tax","tad","den","rex","pee"]

"cet"
"ism"
["kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"]

"hit"
"fbw"
["dit","hot","het","eit","eiw","fiw","fot","fat","faw","hew","hgw","hzw","hyw","fyw","fbw"]

"abc"
"xyz"
["fbc","akc","sbu","abu","fgc","jkc","fgh","fgl","jkl","stu","jtu","stl","jgl","jku","skl","stu","ftl","xtl","xyl","xyz"]

"sand"
"acne"
["slit","bunk","wars","ping","viva","wynn","wows","irks","gang","pool","mock","fort","heel","send","ship","cols","alec","foal","nabs","gaze","giza","mays","dogs","karo","cums","jedi","webb","lend","mire","jose","catt","grow","toss","magi","leis","bead","kara","hoof","than","ires","baas","vein","kari","riga","oars","gags","thug","yawn","wive","view","germ","flab","july","tuck","rory","bean","feed","rhee","jeez","gobs","lath","desk","yoko","cute","zeus","thus","dims","link","dirt","mara","disc","limy","lewd","maud","duly","elsa","hart","rays","rues","camp","lack","okra","tome","math","plug","monk","orly","friz","hogs","yoda","poop","tick","plod","cloy","pees","imps","lead","pope","mall","frey","been","plea","poll","male","teak","soho","glob","bell","mary","hail","scan","yips","like","mull","kory","odor","byte","kaye","word","honk","asks","slid","hopi","toke","gore","flew","tins","mown","oise","hall","vega","sing","fool","boat","bobs","lain","soft","hard","rots","sees","apex","chan","told","woos","unit","scow","gilt","beef","jars","tyre","imus","neon","soap","dabs","rein","ovid","hose","husk","loll","asia","cope","tail","hazy","clad","lash","sags","moll","eddy","fuel","lift","flog","land","sigh","saks","sail","hook","visa","tier","maws","roeg","gila","eyes","noah","hypo","tore","eggs","rove","chap","room","wait","lurk","race","host","dada","lola","gabs","sobs","joel","keck","axed","mead","gust","laid","ends","oort","nose","peer","kept","abet","iran","mick","dead","hags","tens","gown","sick","odis","miro","bill","fawn","sumo","kilt","huge","ores","oran","flag","tost","seth","sift","poet","reds","pips","cape","togo","wale","limn","toll","ploy","inns","snag","hoes","jerk","flux","fido","zane","arab","gamy","raze","lank","hurt","rail","hind","hoot","dogy","away","pest","hoed","pose","lose","pole","alva","dino","kind","clan","dips","soup","veto","edna","damp","gush","amen","wits","pubs","fuzz","cash","pine","trod","gunk","nude","lost","rite","cory","walt","mica","cart","avow","wind","book","leon","life","bang","draw","leek","skis","dram","ripe","mine","urea","tiff","over","gale","weir","defy","norm","tull","whiz","gill","ward","crag","when","mill","firs","sans","flue","reid","ekes","jain","mutt","hems","laps","piss","pall","rowe","prey","cull","knew","size","wets","hurl","wont","suva","girt","prys","prow","warn","naps","gong","thru","livy","boar","sade","amok","vice","slat","emir","jade","karl","loyd","cerf","bess","loss","rums","lats","bode","subs","muss","maim","kits","thin","york","punt","gays","alpo","aids","drag","eras","mats","pyre","clot","step","oath","lout","wary","carp","hums","tang","pout","whip","fled","omar","such","kano","jake","stan","loop","fuss","mini","byrd","exit","fizz","lire","emil","prop","noes","awed","gift","soli","sale","gage","orin","slur","limp","saar","arks","mast","gnat","port","into","geed","pave","awls","cent","cunt","full","dint","hank","mate","coin","tars","scud","veer","coax","bops","uris","loom","shod","crib","lids","drys","fish","edit","dick","erna","else","hahs","alga","moho","wire","fora","tums","ruth","bets","duns","mold","mush","swop","ruby","bolt","nave","kite","ahem","brad","tern","nips","whew","bait","ooze","gino","yuck","drum","shoe","lobe","dusk","cult","paws","anew","dado","nook","half","lams","rich","cato","java","kemp","vain","fees","sham","auks","gish","fire","elam","salt","sour","loth","whit","yogi","shes","scam","yous","lucy","inez","geld","whig","thee","kelp","loaf","harm","tomb","ever","airs","page","laud","stun","paid","goop","cobs","judy","grab","doha","crew","item","fogs","tong","blip","vest","bran","wend","bawl","feel","jets","mixt","tell","dire","devi","milo","deng","yews","weak","mark","doug","fare","rigs","poke","hies","sian","suez","quip","kens","lass","zips","elva","brat","cosy","teri","hull","spun","russ","pupa","weed","pulp","main","grim","hone","cord","barf","olav","gaps","rote","wilt","lars","roll","balm","jana","give","eire","faun","suck","kegs","nita","weer","tush","spry","loge","nays","heir","dope","roar","peep","nags","ates","bane","seas","sign","fred","they","lien","kiev","fops","said","lawn","lind","miff","mass","trig","sins","furl","ruin","sent","cray","maya","clog","puns","silk","axis","grog","jots","dyer","mope","rand","vend","keen","chou","dose","rain","eats","sped","maui","evan","time","todd","skit","lief","sops","outs","moot","faze","biro","gook","fill","oval","skew","veil","born","slob","hyde","twin","eloy","beat","ergs","sure","kobe","eggo","hens","jive","flax","mons","dunk","yest","begs","dial","lodz","burp","pile","much","dock","rene","sago","racy","have","yalu","glow","move","peps","hods","kins","salk","hand","cons","dare","myra","sega","type","mari","pelt","hula","gulf","jugs","flay","fest","spat","toms","zeno","taps","deny","swag","afro","baud","jabs","smut","egos","lara","toes","song","fray","luis","brut","olen","mere","ruff","slum","glad","buds","silt","rued","gelt","hive","teem","ides","sink","ands","wisp","omen","lyre","yuks","curb","loam","darn","liar","pugs","pane","carl","sang","scar","zeds","claw","berg","hits","mile","lite","khan","erik","slug","loon","dena","ruse","talk","tusk","gaol","tads","beds","sock","howe","gave","snob","ahab","part","meir","jell","stir","tels","spit","hash","omit","jinx","lyra","puck","laue","beep","eros","owed","cede","brew","slue","mitt","jest","lynx","wads","gena","dank","volt","gray","pony","veld","bask","fens","argo","work","taxi","afar","boon","lube","pass","lazy","mist","blot","mach","poky","rams","sits","rend","dome","pray","duck","hers","lure","keep","gory","chat","runt","jams","lays","posy","bats","hoff","rock","keri","raul","yves","lama","ramp","vote","jody","pock","gist","sass","iago","coos","rank","lowe","vows","koch","taco","jinn","juno","rape","band","aces","goal","huck","lila","tuft","swan","blab","leda","gems","hide","tack","porn","scum","frat","plum","duds","shad","arms","pare","chin","gain","knee","foot","line","dove","vera","jays","fund","reno","skid","boys","corn","gwyn","sash","weld","ruiz","dior","jess","leaf","pars","cote","zing","scat","nice","dart","only","owls","hike","trey","whys","ding","klan","ross","barb","ants","lean","dopy","hock","tour","grip","aldo","whim","prom","rear","dins","duff","dell","loch","lava","sung","yank","thar","curl","venn","blow","pomp","heat","trap","dali","nets","seen","gash","twig","dads","emmy","rhea","navy","haws","mite","bows","alas","ives","play","soon","doll","chum","ajar","foam","call","puke","kris","wily","came","ales","reef","raid","diet","prod","prut","loot","soar","coed","celt","seam","dray","lump","jags","nods","sole","kink","peso","howl","cost","tsar","uric","sore","woes","sewn","sake","cask","caps","burl","tame","bulk","neva","from","meet","webs","spar","fuck","buoy","wept","west","dual","pica","sold","seed","gads","riff","neck","deed","rudy","drop","vale","flit","romp","peak","jape","jews","fain","dens","hugo","elba","mink","town","clam","feud","fern","dung","newt","mime","deem","inti","gigs","sosa","lope","lard","cara","smug","lego","flex","doth","paar","moon","wren","tale","kant","eels","muck","toga","zens","lops","duet","coil","gall","teal","glib","muir","ails","boer","them","rake","conn","neat","frog","trip","coma","must","mono","lira","craw","sled","wear","toby","reel","hips","nate","pump","mont","died","moss","lair","jibe","oils","pied","hobs","cads","haze","muse","cogs","figs","cues","roes","whet","boru","cozy","amos","tans","news","hake","cots","boas","tutu","wavy","pipe","typo","albs","boom","dyke","wail","woke","ware","rita","fail","slab","owes","jane","rack","hell","lags","mend","mask","hume","wane","acne","team","holy","runs","exes","dole","trim","zola","trek","puma","wacs","veep","yaps","sums","lush","tubs","most","witt","bong","rule","hear","awry","sots","nils","bash","gasp","inch","pens","fies","juts","pate","vine","zulu","this","bare","veal","josh","reek","ours","cowl","club","farm","teat","coat","dish","fore","weft","exam","vlad","floe","beak","lane","ella","warp","goth","ming","pits","rent","tito","wish","amps","says","hawk","ways","punk","nark","cagy","east","paul","bose","solo","teed","text","hews","snip","lips","emit","orgy","icon","tuna","soul","kurd","clod","calk","aunt","bake","copy","acid","duse","kiln","spec","fans","bani","irma","pads","batu","logo","pack","oder","atop","funk","gide","bede","bibs","taut","guns","dana","puff","lyme","flat","lake","june","sets","gull","hops","earn","clip","fell","kama","seal","diaz","cite","chew","cuba","bury","yard","bank","byes","apia","cree","nosh","judo","walk","tape","taro","boot","cods","lade","cong","deft","slim","jeri","rile","park","aeon","fact","slow","goff","cane","earp","tart","does","acts","hope","cant","buts","shin","dude","ergo","mode","gene","lept","chen","beta","eden","pang","saab","fang","whir","cove","perk","fads","rugs","herb","putt","nous","vane","corm","stay","bids","vela","roof","isms","sics","gone","swum","wiry","cram","rink","pert","heap","sikh","dais","cell","peel","nuke","buss","rasp","none","slut","bent","dams","serb","dork","bays","kale","cora","wake","welt","rind","trot","sloe","pity","rout","eves","fats","furs","pogo","beth","hued","edam","iamb","glee","lute","keel","airy","easy","tire","rube","bogy","sine","chop","rood","elbe","mike","garb","jill","gaul","chit","dons","bars","ride","beck","toad","make","head","suds","pike","snot","swat","peed","same","gaza","lent","gait","gael","elks","hang","nerf","rosy","shut","glop","pain","dion","deaf","hero","doer","wost","wage","wash","pats","narc","ions","dice","quay","vied","eons","case","pour","urns","reva","rags","aden","bone","rang","aura","iraq","toot","rome","hals","megs","pond","john","yeps","pawl","warm","bird","tint","jowl","gibe","come","hold","pail","wipe","bike","rips","eery","kent","hims","inks","fink","mott","ices","macy","serf","keys","tarp","cops","sods","feet","tear","benz","buys","colo","boil","sews","enos","watt","pull","brag","cork","save","mint","feat","jamb","rubs","roxy","toys","nosy","yowl","tamp","lobs","foul","doom","sown","pigs","hemp","fame","boor","cube","tops","loco","lads","eyre","alta","aged","flop","pram","lesa","sawn","plow","aral","load","lied","pled","boob","bert","rows","zits","rick","hint","dido","fist","marc","wuss","node","smog","nora","shim","glut","bale","perl","what","tort","meek","brie","bind","cake","psst","dour","jove","tree","chip","stud","thou","mobs","sows","opts","diva","perm","wise","cuds","sols","alan","mild","pure","gail","wins","offs","nile","yelp","minn","tors","tran","homy","sadr","erse","nero","scab","finn","mich","turd","then","poem","noun","oxus","brow","door","saws","eben","wart","wand","rosa","left","lina","cabs","rapt","olin","suet","kalb","mans","dawn","riel","temp","chug","peal","drew","null","hath","many","took","fond","gate","sate","leak","zany","vans","mart","hess","home","long","dirk","bile","lace","moog","axes","zone","fork","duct","rico","rife","deep","tiny","hugh","bilk","waft","swig","pans","with","kern","busy","film","lulu","king","lord","veda","tray","legs","soot","ells","wasp","hunt","earl","ouch","diem","yell","pegs","blvd","polk","soda","zorn","liza","slop","week","kill","rusk","eric","sump","haul","rims","crop","blob","face","bins","read","care","pele","ritz","beau","golf","drip","dike","stab","jibs","hove","junk","hoax","tats","fief","quad","peat","ream","hats","root","flak","grit","clap","pugh","bosh","lock","mute","crow","iced","lisa","bela","fems","oxes","vies","gybe","huff","bull","cuss","sunk","pups","fobs","turf","sect","atom","debt","sane","writ","anon","mayo","aria","seer","thor","brim","gawk","jack","jazz","menu","yolk","surf","libs","lets","bans","toil","open","aced","poor","mess","wham","fran","gina","dote","love","mood","pale","reps","ines","shot","alar","twit","site","dill","yoga","sear","vamp","abel","lieu","cuff","orbs","rose","tank","gape","guam","adar","vole","your","dean","dear","hebe","crab","hump","mole","vase","rode","dash","sera","balk","lela","inca","gaea","bush","loud","pies","aide","blew","mien","side","kerr","ring","tess","prep","rant","lugs","hobo","joke","odds","yule","aida","true","pone","lode","nona","weep","coda","elmo","skim","wink","bras","pier","bung","pets","tabs","ryan","jock","body","sofa","joey","zion","mace","kick","vile","leno","bali","fart","that","redo","ills","jogs","pent","drub","slaw","tide","lena","seep","gyps","wave","amid","fear","ties","flan","wimp","kali","shun","crap","sage","rune","logs","cain","digs","abut","obit","paps","rids","fair","hack","huns","road","caws","curt","jute","fisk","fowl","duty","holt","miss","rude","vito","baal","ural","mann","mind","belt","clem","last","musk","roam","abed","days","bore","fuze","fall","pict","dump","dies","fiat","vent","pork","eyed","docs","rive","spas","rope","ariz","tout","game","jump","blur","anti","lisp","turn","sand","food","moos","hoop","saul","arch","fury","rise","diss","hubs","burs","grid","ilks","suns","flea","soil","lung","want","nola","fins","thud","kidd","juan","heps","nape","rash","burt","bump","tots","brit","mums","bole","shah","tees","skip","limb","umps","ache","arcs","raft","halo","luce","bahs","leta","conk","duos","siva","went","peek","sulk","reap","free","dubs","lang","toto","hasp","ball","rats","nair","myst","wang","snug","nash","laos","ante","opal","tina","pore","bite","haas","myth","yugo","foci","dent","bade","pear","mods","auto","shop","etch","lyly","curs","aron","slew","tyro","sack","wade","clio","gyro","butt","icky","char","itch","halt","gals","yang","tend","pact","bees","suit","puny","hows","nina","brno","oops","lick","sons","kilo","bust","nome","mona","dull","join","hour","papa","stag","bern","wove","lull","slip","laze","roil","alto","bath","buck","alma","anus","evil","dumb","oreo","rare","near","cure","isis","hill","kyle","pace","comb","nits","flip","clop","mort","thea","wall","kiel","judd","coop","dave","very","amie","blah","flub","talc","bold","fogy","idea","prof","horn","shoo","aped","pins","helm","wees","beer","womb","clue","alba","aloe","fine","bard","limo","shaw","pint","swim","dust","indy","hale","cats","troy","wens","luke","vern","deli","both","brig","daub","sara","sued","bier","noel","olga","dupe","look","pisa","knox","murk","dame","matt","gold","jame","toge","luck","peck","tass","calf","pill","wore","wadi","thur","parr","maul","tzar","ones","lees","dark","fake","bast","zoom","here","moro","wine","bums","cows","jean","palm","fume","plop","help","tuba","leap","cans","back","avid","lice","lust","polo","dory","stew","kate","rama","coke","bled","mugs","ajax","arts","drug","pena","cody","hole","sean","deck","guts","kong","bate","pitt","como","lyle","siam","rook","baby","jigs","bret","bark","lori","reba","sups","made","buzz","gnaw","alps","clay","post","viol","dina","card","lana","doff","yups","tons","live","kids","pair","yawl","name","oven","sirs","gyms","prig","down","leos","noon","nibs","cook","safe","cobb","raja","awes","sari","nerd","fold","lots","pete","deal","bias","zeal","girl","rage","cool","gout","whey","soak","thaw","bear","wing","nagy","well","oink","sven","kurt","etna","held","wood","high","feta","twee","ford","cave","knot","tory","ibis","yaks","vets","foxy","sank","cone","pius","tall","seem","wool","flap","gird","lore","coot","mewl","sere","real","puts","sell","nuts","foil","lilt","saga","heft","dyed","goat","spew","daze","frye","adds","glen","tojo","pixy","gobi","stop","tile","hiss","shed","hahn","baku","ahas","sill","swap","also","carr","manx","lime","debs","moat","eked","bola","pods","coon","lacy","tube","minx","buff","pres","clew","gaff","flee","burn","whom","cola","fret","purl","wick","wigs","donn","guys","toni","oxen","wite","vial","spam","huts","vats","lima","core","eula","thad","peon","erie","oats","boyd","cued","olaf","tams","secs","urey","wile","penn","bred","rill","vary","sues","mail","feds","aves","code","beam","reed","neil","hark","pols","gris","gods","mesa","test","coup","heed","dora","hied","tune","doze","pews","oaks","bloc","tips","maid","goof","four","woof","silo","bray","zest","kiss","yong","file","hilt","iris","tuns","lily","ears","pant","jury","taft","data","gild","pick","kook","colt","bohr","anal","asps","babe","bach","mash","biko","bowl","huey","jilt","goes","guff","bend","nike","tami","gosh","tike","gees","urge","path","bony","jude","lynn","lois","teas","dunn","elul","bonn","moms","bugs","slay","yeah","loan","hulk","lows","damn","nell","jung","avis","mane","waco","loin","knob","tyke","anna","hire","luau","tidy","nuns","pots","quid","exec","hans","hera","hush","shag","scot","moan","wald","ursa","lorn","hunk","loft","yore","alum","mows","slog","emma","spud","rice","worn","erma","need","bags","lark","kirk","pooh","dyes","area","dime","luvs","foch","refs","cast","alit","tugs","even","role","toed","caph","nigh","sony","bide","robs","folk","daft","past","blue","flaw","sana","fits","barr","riot","dots","lamp","cock","fibs","harp","tent","hate","mali","togs","gear","tues","bass","pros","numb","emus","hare","fate","wife","mean","pink","dune","ares","dine","oily","tony","czar","spay","push","glum","till","moth","glue","dive","scad","pops","woks","andy","leah","cusp","hair","alex","vibe","bulb","boll","firm","joys","tara","cole","levy","owen","chow","rump","jail","lapp","beet","slap","kith","more","maps","bond","hick","opus","rust","wist","shat","phil","snow","lott","lora","cary","mote","rift","oust","klee","goad","pith","heep","lupe","ivan","mimi","bald","fuse","cuts","lens","leer","eyry","know","razz","tare","pals","geek","greg","teen","clef","wags","weal","each","haft","nova","waif","rate","katy","yale","dale","leas","axum","quiz","pawn","fend","capt","laws","city","chad","coal","nail","zaps","sort","loci","less","spur","note","foes","fags","gulp","snap","bogs","wrap","dane","melt","ease","felt","shea","calm","star","swam","aery","year","plan","odin","curd","mira","mops","shit","davy","apes","inky","hues","lome","bits","vila","show","best","mice","gins","next","roan","ymir","mars","oman","wild","heal","plus","erin","rave","robe","fast","hutu","aver","jodi","alms","yams","zero","revs","wean","chic","self","jeep","jobs","waxy","duel","seek","spot","raps","pimp","adan","slam","tool","morn","futz","ewes","errs","knit","rung","kans","muff","huhs","tows","lest","meal","azov","gnus","agar","sips","sway","otis","tone","tate","epic","trio","tics","fade","lear","owns","robt","weds","five","lyon","terr","arno","mama","grey","disk","sept","sire","bart","saps","whoa","turk","stow","pyle","joni","zinc","negs","task","leif","ribs","malt","nine","bunt","grin","dona","nope","hams","some","molt","smit","sacs","joan","slav","lady","base","heck","list","take","herd","will","nubs","burg","hugs","peru","coif","zoos","nick","idol","levi","grub","roth","adam","elma","tags","tote","yaws","cali","mete","lula","cubs","prim","luna","jolt","span","pita","dodo","puss","deer","term","dolt","goon","gary","yarn","aims","just","rena","tine","cyst","meld","loki","wong","were","hung","maze","arid","cars","wolf","marx","faye","eave","raga","flow","neal","lone","anne","cage","tied","tilt","soto","opel","date","buns","dorm","kane","akin","ewer","drab","thai","jeer","grad","berm","rods","saki","grus","vast","late","lint","mule","risk","labs","snit","gala","find","spin","ired","slot","oafs","lies","mews","wino","milk","bout","onus","tram","jaws","peas","cleo","seat","gums","cold","vang","dewy","hood","rush","mack","yuan","odes","boos","jami","mare","plot","swab","borg","hays","form","mesh","mani","fife","good","gram","lion","myna","moor","skin","posh","burr","rime","done","ruts","pays","stem","ting","arty","slag","iron","ayes","stub","oral","gets","chid","yens","snub","ages","wide","bail","verb","lamb","bomb","army","yoke","gels","tits","bork","mils","nary","barn","hype","odom","avon","hewn","rios","cams","tact","boss","oleo","duke","eris","gwen","elms","deon","sims","quit","nest","font","dues","yeas","zeta","bevy","gent","torn","cups","worm","baum","axon","purr","vise","grew","govs","meat","chef","rest","lame"]
*/
```