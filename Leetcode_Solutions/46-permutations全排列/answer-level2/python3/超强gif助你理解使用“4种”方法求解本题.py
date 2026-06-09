# 做题不是目的，`触类旁通`是我们需要掌握的技能！
如果你基本是按照顺序来做的，那么你之前应该已经遇到[31.下一个排列](https://leetcode-cn.com/problems/next-permutation/)了，你通过了吗？你当时是怎么求解的？本题能不能用上31题的结果呢？再往前推一点，[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/)应该也做了，当时是用什么方法求解的？回溯法抑或是其他一些很巧妙的方法？能不能从中得到什么启发呢？

下面我将结合回溯法以及联合31题和22题，举一反三的求解本题，希望对你有所启发。

# 1.投机取巧——库函数`itertools.permutations`
python自带的库函数，直接输出结果，哈哈哈，偷笑一下。如果不知道它（我原来也不知道，从其他题解看到的，索性调用一下好了 嘎嘎）或者其他语言没有提供对应的库函数也没关系，自己动手(跟着我左手右手一个慢动作😀)丰衣足食咯
```python []
def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))
```
# 2.宇宙无敌——回溯法
关于回溯法，题解中很多都是这个方法。我在这里也不介绍它的一些概念了。主要就是通过下面这个形象生动的GIF，带你从程序运行的的角度，体验一遍`nums=[1,2,3]`的运行过程以及相应变量的变化过程，相信一定会有很大帮助。
#### 请先自己看一下程序
```python []
class Solution:
    def permute(self, nums): 
        def backtrack(nums,tem):
            if nums==[]:
                if tem not in res:
                    res.append(tem[:])
            else:
                for i in range(len(nums)):
                    tem.append(nums[i])
                    backtrack(nums[0:i]+nums[i+1:],tem)
            if tem == []:
                return
            tem.pop()

        res = []
        tem = []
        backtrack(nums,tem)
        return res
```
#### gif中需要注意的点：
1. 右边是`程序运行队列图`，程序执行到的语句将 变红 显示。
2. 针对for循环，已经遍历过的数字将 变红 显示。全部变红代表遍历完成，此时将继续执行后续语句。
3. 图中由上而下`回溯深度`依次增加，其中回溯深度指的是当前程序运行到本段，调用backtrack（自己），程序进入了第二层执行；而第一层的程序相当于“停止”在了backtrack行，等待第二层运行完返回结果后再继续往后执行。反应在图中即为backtrack变灰、程序运行队列图叠加了下一个backtrack函数。
4. 动画在主程序第一轮for循环时较慢，第二轮开始就比较快了。动画和程序执行图中变红的语句对应着看会更便于理解！
5. gif时间较长，不要着急，慢慢的多看几遍。
![7.gif](https://pic.leetcode-cn.com/30cb68d56925ecebddaa4dba35ff23e85a0442cb3b2ecba10246a8f5cb207bdf-7.gif)

#### gig比较快，希望下面的图片能让你缓一缓

<![幻灯片1.JPG](https://pic.leetcode-cn.com/7f65856eb32d9459ae5d30a3ee42a7d6cf34af1e2781f0e70e0e0745b3b01162-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/eb5f1b8f65a40218d5d507ae473025b382ee2acb3e73377bb183b7e8a47db893-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/a97b8a36d9330842b93bd2abfdb94fc6348c4281839bdd08692c95003c19aebd-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/4d9548bf52255252800a113685265db01c33722d411a6a6fee872a35b462bcb1-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/461f3de5ebefbe2f321242a6b89904665d32a941ff879921516429d5eff0ec2e-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/8cfb6af4c284e681e7f2a78b39df80e5bf41a67cea97974297697524155b31a3-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/14c9728c718d4e81bb6f955f89d475697650552ee3ec11efa29322a58c91cc5a-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/8a5b5e29e9159f26c4507fb516832c6d09e284e6da59757e0be09731fce62561-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/54b961a6b3a908126d777aaffa63189ce71e93a2f5d397524777acad41aa3acf-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/941b3e991fa03940b2f275ff0844a835d2a05892703415987e162a53f4632f04-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/c79d7f189ceb47252f327344ebf319c4cb7e0c628607eca6fc3fa69922bca0bb-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/a36e3569462e849235b090fbfaf8756685ee17cab212024067ab799392af4409-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/7181881edb0db59a38075eda2102078ccb74d729be5dc840656a384cd4a63d64-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/778fccc15b75b5dc89e847aec63d0533ee7b8e1270825708c6033ae20a6d6c1c-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG),![幻灯片15.JPG](https://pic.leetcode-cn.com/61e70f67af2d4764fd38f71e4a8bfc8315dc6c26d60fc77f38973e2ebe40569b-%E5%B9%BB%E7%81%AF%E7%89%8715.JPG),![幻灯片16.JPG](https://pic.leetcode-cn.com/0cac04fef7f102b0602abdd30f782b553cee648db7d17f5269879eab2a071190-%E5%B9%BB%E7%81%AF%E7%89%8716.JPG),![幻灯片17.JPG](https://pic.leetcode-cn.com/1901bbffeb3a24ec486f3ea4ef58f7573632d40a2c51d3830e405f441dd4b16f-%E5%B9%BB%E7%81%AF%E7%89%8717.JPG),![幻灯片18.JPG](https://pic.leetcode-cn.com/02c74bd75974e66b7d66c5f67b30ae165ca07b5313d264f51969560a1e657c3b-%E5%B9%BB%E7%81%AF%E7%89%8718.JPG),![幻灯片19.JPG](https://pic.leetcode-cn.com/60b1ccf1014abd69df09d148257fc266192099e2553efec344ba527fa8928813-%E5%B9%BB%E7%81%AF%E7%89%8719.JPG),![幻灯片20.JPG](https://pic.leetcode-cn.com/3455685fc3083b72a627bfc4b4528b7ad335783116a4aab153a94f7bf13a05d1-%E5%B9%BB%E7%81%AF%E7%89%8720.JPG),![幻灯片21.JPG](https://pic.leetcode-cn.com/e102876e7d9d97b495f7474078cfffb80c8e031868f5d163115ff7ab920be99f-%E5%B9%BB%E7%81%AF%E7%89%8721.JPG),![幻灯片22.JPG](https://pic.leetcode-cn.com/000caa398dcf546c439b55f2a64577797c431f766a64b55a6aec30a27e6f2b18-%E5%B9%BB%E7%81%AF%E7%89%8722.JPG),![幻灯片23.JPG](https://pic.leetcode-cn.com/174273f0df5b764fc5eeedd99e7d5894c2fde32269926f5c5bc48847fff9577c-%E5%B9%BB%E7%81%AF%E7%89%8723.JPG),![幻灯片24.JPG](https://pic.leetcode-cn.com/1357377194806652bcc5534ed6313b9cbd64c51f0c86071ace59da7258aafde1-%E5%B9%BB%E7%81%AF%E7%89%8724.JPG),![幻灯片25.JPG](https://pic.leetcode-cn.com/55e84432fc66d6fcba7d053a8821d21dc57b338a0e2543fbb81088e55ffbd29c-%E5%B9%BB%E7%81%AF%E7%89%8725.JPG),![幻灯片26.JPG](https://pic.leetcode-cn.com/8f7ffab6fd7ed5086e9b3cde7434757b8750de542ac744b363a7cd766efff5e1-%E5%B9%BB%E7%81%AF%E7%89%8726.JPG),![幻灯片27.JPG](https://pic.leetcode-cn.com/43b105df8cabcf30d6caf238e781c4149d57e3720024715990ce457c574b992b-%E5%B9%BB%E7%81%AF%E7%89%8727.JPG),![幻灯片28.JPG](https://pic.leetcode-cn.com/6d0e63c87bac9e4e7e22e59ae6ba94c5e86d087d873fa8490b999bda291ac550-%E5%B9%BB%E7%81%AF%E7%89%8728.JPG),![幻灯片29.JPG](https://pic.leetcode-cn.com/a090c7222220a2d28ae40e2e5d509a289813ae77c41183bb1cd99a3c8369554b-%E5%B9%BB%E7%81%AF%E7%89%8729.JPG),![幻灯片30.JPG](https://pic.leetcode-cn.com/62ae96eb65964ae62ee7805f4276688d5b75afd26a2b74e2bdb3b7aac374b57c-%E5%B9%BB%E7%81%AF%E7%89%8730.JPG),![幻灯片31.JPG](https://pic.leetcode-cn.com/0c0ba47d1d1a40963ee10c2d7f06bafe6bebcb7da666840e185f92910e2fd689-%E5%B9%BB%E7%81%AF%E7%89%8731.JPG),![幻灯片32.JPG](https://pic.leetcode-cn.com/79034a950ebf36bf47917ce56ec3c8bc9908c4909fae9fdd50a851f03f1b6f70-%E5%B9%BB%E7%81%AF%E7%89%8732.JPG),![幻灯片33.JPG](https://pic.leetcode-cn.com/f362dbe65d1a8d782f1f11e3711b7693f6f10a025a6612d7d59344b55dbfc62d-%E5%B9%BB%E7%81%AF%E7%89%8733.JPG),![幻灯片34.JPG](https://pic.leetcode-cn.com/7310d8a3813a667f45cd0610ae24edce99ba09813de1de5881f8f2f15fad06f9-%E5%B9%BB%E7%81%AF%E7%89%8734.JPG),![幻灯片35.JPG](https://pic.leetcode-cn.com/35903245ddafa4e5e32e93f8740564e1309f0476a7298e637d816ee85652c894-%E5%B9%BB%E7%81%AF%E7%89%8735.JPG),![幻灯片36.JPG](https://pic.leetcode-cn.com/4bc6884ff01240383ec486e4d11002704578ffa7540aec8b0a64c6f010762e20-%E5%B9%BB%E7%81%AF%E7%89%8736.JPG),![幻灯片37.JPG](https://pic.leetcode-cn.com/91104121fc59095de3a679aa9dadf85c163307f7e429446225ddf9379720c42b-%E5%B9%BB%E7%81%AF%E7%89%8737.JPG),![幻灯片38.JPG](https://pic.leetcode-cn.com/416d40f0c11bd04a4b4fe6450b53f304be104386fcc14d43e8ed94711722d381-%E5%B9%BB%E7%81%AF%E7%89%8738.JPG),![幻灯片39.JPG](https://pic.leetcode-cn.com/831a01dc5aa73e7afff739574d043c4d349597a1128e10609e36ea2c92f27d51-%E5%B9%BB%E7%81%AF%E7%89%8739.JPG),![幻灯片40.JPG](https://pic.leetcode-cn.com/1b098194a181ca6410d8616f3a0ece994c49e54e696dc17584017d75a8f98499-%E5%B9%BB%E7%81%AF%E7%89%8740.JPG),![幻灯片41.JPG](https://pic.leetcode-cn.com/081828b91691e97b8dac4f6e4748f0cd567b55cb7b398650736b06d2cd4f06ae-%E5%B9%BB%E7%81%AF%E7%89%8741.JPG),![幻灯片42.JPG](https://pic.leetcode-cn.com/3263ff745f48f2783398f6075be9c77008d78ada0df29e8bac407793eed8a515-%E5%B9%BB%E7%81%AF%E7%89%8742.JPG),![幻灯片43.JPG](https://pic.leetcode-cn.com/6ec24ea869604b467746e2cd977a7e5af92dd7a26099c60d48e94ff605676ac1-%E5%B9%BB%E7%81%AF%E7%89%8743.JPG),![幻灯片44.JPG](https://pic.leetcode-cn.com/e956f000a2d5bcd53bb22a370560fafe202419fdb6c93351cba060f68583ad9c-%E5%B9%BB%E7%81%AF%E7%89%8744.JPG),![幻灯片45.JPG](https://pic.leetcode-cn.com/32bc124daf3908b885edc6d4e65486e305c649e0c54105bbd85712b3277cd381-%E5%B9%BB%E7%81%AF%E7%89%8745.JPG),![幻灯片46.JPG](https://pic.leetcode-cn.com/4664ceff0b0b253438dc2b1f9c7997a67169fc85003008463fbfb53645dfb239-%E5%B9%BB%E7%81%AF%E7%89%8746.JPG),![幻灯片47.JPG](https://pic.leetcode-cn.com/5a0a165152e60fe088f516763ffb60ace17414e66f9d4fc3b7e8834b79408742-%E5%B9%BB%E7%81%AF%E7%89%8747.JPG),![幻灯片48.JPG](https://pic.leetcode-cn.com/d16291ab65e302988cbb6cfcdff661e5f5bc086c4576ef8b1c0d7b9f9f082e99-%E5%B9%BB%E7%81%AF%E7%89%8748.JPG),![幻灯片49.JPG](https://pic.leetcode-cn.com/0d7c485d6e751c18463de963afa017ce7130ffea2dd7a0d1c50af7ad9b2f08dd-%E5%B9%BB%E7%81%AF%E7%89%8749.JPG),![幻灯片50.JPG](https://pic.leetcode-cn.com/217b1688cdc88d4d7057d18f426f7ec2750aca422034289c49aeb6ebbabd8592-%E5%B9%BB%E7%81%AF%E7%89%8750.JPG),![幻灯片51.JPG](https://pic.leetcode-cn.com/f2fc86d98be014cde7b4a84d771fe43c6fdf50896b017092d79c7939ce01be66-%E5%B9%BB%E7%81%AF%E7%89%8751.JPG),![幻灯片52.JPG](https://pic.leetcode-cn.com/cb4c37bfabf51722ea67f7427808d105482cca445b67c22551abd4cbe3987696-%E5%B9%BB%E7%81%AF%E7%89%8752.JPG),![幻灯片53.JPG](https://pic.leetcode-cn.com/d68ed2bff08c2265417a1eea75e1f24408af54e872bdf812abdf63e5376397d5-%E5%B9%BB%E7%81%AF%E7%89%8753.JPG),![幻灯片54.JPG](https://pic.leetcode-cn.com/9ef761fbe717777fcd783c05718422c15cc077af01cf5b678f5821c9ab6d2b71-%E5%B9%BB%E7%81%AF%E7%89%8754.JPG),![幻灯片55.JPG](https://pic.leetcode-cn.com/517a08a7573df7e4fae260cfe09f67dc9ad3497493369294c92e9c75fee20fa7-%E5%B9%BB%E7%81%AF%E7%89%8755.JPG),![幻灯片56.JPG](https://pic.leetcode-cn.com/4c759a8819f8d4a6ddbbfa72a35528b5782a90375b3f1619ff6eb2444a38bbe0-%E5%B9%BB%E7%81%AF%E7%89%8756.JPG),![幻灯片57.JPG](https://pic.leetcode-cn.com/d8c2fa4db55ac58a17cb24b81b8be507904f197f18a7d4206ccfe1eff44d5732-%E5%B9%BB%E7%81%AF%E7%89%8757.JPG),![幻灯片58.JPG](https://pic.leetcode-cn.com/59d4487faf8d56c5e8840e39bbe13bfd3a075c804d8f7d71c54086fad5e3b321-%E5%B9%BB%E7%81%AF%E7%89%8758.JPG),![幻灯片59.JPG](https://pic.leetcode-cn.com/4b7030d6290dc3722bbe9631f7f54e968ef01804fde2f2eb614f8741257494bf-%E5%B9%BB%E7%81%AF%E7%89%8759.JPG),![幻灯片60.JPG](https://pic.leetcode-cn.com/fafad10fa11648c513808ea982a448fc99d615d9d39ee18a7aa403c024c5142a-%E5%B9%BB%E7%81%AF%E7%89%8760.JPG),![幻灯片61.JPG](https://pic.leetcode-cn.com/fd30ad47b85ace9fb6ab99afa21fa100205942bb15c0066129cedd567824dbd0-%E5%B9%BB%E7%81%AF%E7%89%8761.JPG),![幻灯片62.JPG](https://pic.leetcode-cn.com/843cad012601d95ca90f47ddbd19e6c5dbee6895ca04ac1f5c5c6684c98ee10d-%E5%B9%BB%E7%81%AF%E7%89%8762.JPG),![幻灯片63.JPG](https://pic.leetcode-cn.com/b3a70bb21332ad86986a2672d48dfc8ff020d211d69ae5092a3b9c0684640a69-%E5%B9%BB%E7%81%AF%E7%89%8763.JPG),![幻灯片64.JPG](https://pic.leetcode-cn.com/caba908cbda93e5f4c765a3b9edf6b840fd9580ebab0df5a95c9c5c6e8a77177-%E5%B9%BB%E7%81%AF%E7%89%8764.JPG),![幻灯片65.JPG](https://pic.leetcode-cn.com/e7322f307e060be7e375e4f0fe871e4ee254a114acd7ec0f0b70bfa12407e27e-%E5%B9%BB%E7%81%AF%E7%89%8765.JPG),![幻灯片66.JPG](https://pic.leetcode-cn.com/f08509fc9a273905eb8d8f63c94bb6993ca151cc2effe94b47347f5dc548269a-%E5%B9%BB%E7%81%AF%E7%89%8766.JPG),![幻灯片67.JPG](https://pic.leetcode-cn.com/12e972158ef9515c483aef35b4d79b09a864ba5d88c7855983f2568ac7939f4a-%E5%B9%BB%E7%81%AF%E7%89%8767.JPG),![幻灯片68.JPG](https://pic.leetcode-cn.com/d59f3dc5aadf788967628069f60401eb7f068c390c6550664efdd1b817749a24-%E5%B9%BB%E7%81%AF%E7%89%8768.JPG),![幻灯片69.JPG](https://pic.leetcode-cn.com/0cfbb8789464c98b995780a80525366689b7ef43ef07bd46b801020ce2c051b0-%E5%B9%BB%E7%81%AF%E7%89%8769.JPG),![幻灯片70.JPG](https://pic.leetcode-cn.com/b56b963c2485fef06d8a70922e4bdc44ba9f663d5a5115d58e5472f26825bc3d-%E5%B9%BB%E7%81%AF%E7%89%8770.JPG),![幻灯片71.JPG](https://pic.leetcode-cn.com/b59cb1de56ee657d65b6ddee4a0be317d55fa8bcd8ba098eb6f60b38d43190df-%E5%B9%BB%E7%81%AF%E7%89%8771.JPG),![幻灯片72.JPG](https://pic.leetcode-cn.com/62f706f64e5cf221069fae2b310d645b883719fb755925be7d9bd977e3b11d72-%E5%B9%BB%E7%81%AF%E7%89%8772.JPG),![幻灯片73.JPG](https://pic.leetcode-cn.com/7b39c6f624c52890c760d5fd5476883be541b01200c898de6ea499a2be2529a8-%E5%B9%BB%E7%81%AF%E7%89%8773.JPG),![幻灯片74.JPG](https://pic.leetcode-cn.com/8de45309218e57226c4a5d2d18781add77a2b711432386fb1f1d38955f8865b2-%E5%B9%BB%E7%81%AF%E7%89%8774.JPG),![幻灯片75.JPG](https://pic.leetcode-cn.com/c063f2f395d13ff9fdf1247c6cb2e8028601c87e413cdadb6dabee15abd60a0e-%E5%B9%BB%E7%81%AF%E7%89%8775.JPG),![幻灯片76.JPG](https://pic.leetcode-cn.com/c57bac509adf667c110b3d763c8e925bf5a7aa0edcb6840e77d321d5df17a32f-%E5%B9%BB%E7%81%AF%E7%89%8776.JPG),![幻灯片77.JPG](https://pic.leetcode-cn.com/e5643953ea222cdea24cb5c2b4bb1c5a4806f18b0cc2ff715cf738fd7fe8afae-%E5%B9%BB%E7%81%AF%E7%89%8777.JPG),![幻灯片78.JPG](https://pic.leetcode-cn.com/a4f83337a4038d4f7fe1e8af2222586fb504b535b3e84f2f33cc4bdf1b8390dc-%E5%B9%BB%E7%81%AF%E7%89%8778.JPG),![幻灯片79.JPG](https://pic.leetcode-cn.com/dc972484fd343ec509d717aa1bff63966012a91164fa6c0447f3d79eea474da2-%E5%B9%BB%E7%81%AF%E7%89%8779.JPG)>


# 3.见异思迁——[31题](https://leetcode-cn.com/problems/next-permutation/)
31题是让我们求解输入数组的下一个排列，假设我们输入的就是最小的值1234，那么31题将输出1243；再将结果送入31题的程序，将输出1324...也就是说我们可以将31题的程序变成本题的一个函数，循环调用之并把结果保存到一个列表中，直到结果为最大值时停止。

下面以`nums=[1,2,3,4]`为例图解31题的思路(动画从1432到2134的时候来回往复了3遍，便于观察选取数字以及排序的过程)：
![8.gif](https://pic.leetcode-cn.com/bdf817ef655d611988063a65a12c8f16a3f75a87cfd6eb11b3f58756629a9028-8.gif)

#### gig比较快，希望下面的图片能让你缓一缓
<![幻灯片80.JPG](https://pic.leetcode-cn.com/270abb0eafdc0fde483d9dd6aa1c8b0bd375bb0818f2ffb0387129825ae18d6b-%E5%B9%BB%E7%81%AF%E7%89%8780.JPG),![幻灯片81.JPG](https://pic.leetcode-cn.com/655b0e4a7c86507d845805ccd64e6499ae5f31fb21d0e24fcdbf61b4fd989374-%E5%B9%BB%E7%81%AF%E7%89%8781.JPG),![幻灯片82.JPG](https://pic.leetcode-cn.com/988a5ddbcdd57eeab2a70a6eb5a5bb3fb80f796a57e0a9518cfa2330eb2c5e00-%E5%B9%BB%E7%81%AF%E7%89%8782.JPG),![幻灯片83.JPG](https://pic.leetcode-cn.com/5552234f74cb8b1dde3814cbf850e749c41a2a2bcfe2a3c8efdce810510f1092-%E5%B9%BB%E7%81%AF%E7%89%8783.JPG),![幻灯片84.JPG](https://pic.leetcode-cn.com/a8ab4964219ae9dfa31df85cf049c365b1ce0dcc335111ce177275eab02248ab-%E5%B9%BB%E7%81%AF%E7%89%8784.JPG),![幻灯片85.JPG](https://pic.leetcode-cn.com/7059e744420423ccd876b1cce330eeb5134cf26778dc568d5268a0afa390743d-%E5%B9%BB%E7%81%AF%E7%89%8785.JPG),![幻灯片86.JPG](https://pic.leetcode-cn.com/4c24ef94b887e88887d44f70852887fc49e87f6a6ca1a49fdff0b5db7ab6d83c-%E5%B9%BB%E7%81%AF%E7%89%8786.JPG),![幻灯片87.JPG](https://pic.leetcode-cn.com/0e359af301c13e0cedf0377ef33d6622d6198ca98afd334876896a52b82a48f3-%E5%B9%BB%E7%81%AF%E7%89%8787.JPG),![幻灯片88.JPG](https://pic.leetcode-cn.com/f5ee9e66098c8090bb782dac37548b395e0fd37532f24c8ffb7154e347ce9d19-%E5%B9%BB%E7%81%AF%E7%89%8788.JPG),![幻灯片89.JPG](https://pic.leetcode-cn.com/6c6f6c2106b2746842189daaf7a08ff303abdf7a44b143eaf6282c704e3d3a0b-%E5%B9%BB%E7%81%AF%E7%89%8789.JPG),![幻灯片90.JPG](https://pic.leetcode-cn.com/576e9968b4d1e33bcbb4c323e92e9115af6382786305b1bc807273190da16ef4-%E5%B9%BB%E7%81%AF%E7%89%8790.JPG),![幻灯片91.JPG](https://pic.leetcode-cn.com/35d7ef9ee3b6e66f82568901d882a68386f27ab74989a2b388e44ec11708b526-%E5%B9%BB%E7%81%AF%E7%89%8791.JPG),![幻灯片92.JPG](https://pic.leetcode-cn.com/2cc5d9d25597caf4caf6b02178b6898cc1f986db30abb26fc36fccf5c0eedc94-%E5%B9%BB%E7%81%AF%E7%89%8792.JPG),![幻灯片93.JPG](https://pic.leetcode-cn.com/61bc5bff1dfdf3600bce8d5144b66023a6823c2c6f83a7b75b98cb9ebea9f3e7-%E5%B9%BB%E7%81%AF%E7%89%8793.JPG),![幻灯片94.JPG](https://pic.leetcode-cn.com/c1ac7d60e61167cd06e5777e3e01f64d6e831f7192bc2ee6df4841d39142ad67-%E5%B9%BB%E7%81%AF%E7%89%8794.JPG),![幻灯片95.JPG](https://pic.leetcode-cn.com/80de3f6187c834ab9f413c6420121f32668cec01b549538e5738e0d138a3bcfe-%E5%B9%BB%E7%81%AF%E7%89%8795.JPG),![幻灯片96.JPG](https://pic.leetcode-cn.com/e600593159628a15f6f9f34fa9267977ad41dcd4c3ad61f3d092de2c6de40b1a-%E5%B9%BB%E7%81%AF%E7%89%8796.JPG),![幻灯片97.JPG](https://pic.leetcode-cn.com/42de687557c577052e5344277e3401dde4eafd1a8de8d1daf03e2e40c158715f-%E5%B9%BB%E7%81%AF%E7%89%8797.JPG),![幻灯片98.JPG](https://pic.leetcode-cn.com/7d752d00c031f5bce74c9e8229644a3530d27460f842f6202ffa3b74b8e1e190-%E5%B9%BB%E7%81%AF%E7%89%8798.JPG),![幻灯片99.JPG](https://pic.leetcode-cn.com/b101f1e38f8de88a50abf50a54332f4d46f2baa3cdd6fcf7c8027550cec177be-%E5%B9%BB%E7%81%AF%E7%89%8799.JPG),![幻灯片100.JPG](https://pic.leetcode-cn.com/47488a1fbf384b3f444d43f804e8aa65e9869833eae864125b435b44d8285d32-%E5%B9%BB%E7%81%AF%E7%89%87100.JPG),![幻灯片101.JPG](https://pic.leetcode-cn.com/d21bb1bcbd6f1cecb5accbcf2ada7d473a0c941f576a4cb54977322963c7fb74-%E5%B9%BB%E7%81%AF%E7%89%87101.JPG),![幻灯片102.JPG](https://pic.leetcode-cn.com/ca61650af3d2817b7f03b8b8ae3fda9ed0b70cac22d36e91b467b7e7e128d821-%E5%B9%BB%E7%81%AF%E7%89%87102.JPG),![幻灯片103.JPG](https://pic.leetcode-cn.com/7ba3669e7dbd64f2b9214d9429fa8ef203f72ffed8a9479b922aed2724d4bd98-%E5%B9%BB%E7%81%AF%E7%89%87103.JPG),![幻灯片104.JPG](https://pic.leetcode-cn.com/005e3ab04cfb5207aa55bcc88e1073fbd3f3a595cca8e69d266a5cf622b53dd9-%E5%B9%BB%E7%81%AF%E7%89%87104.JPG),![幻灯片105.JPG](https://pic.leetcode-cn.com/1067422dd6e82ecb5f82aadbc0fdeee5d52bf475f3f96d37e872aec443a454fc-%E5%B9%BB%E7%81%AF%E7%89%87105.JPG),![幻灯片106.JPG](https://pic.leetcode-cn.com/7ab50d1e339c8be8781a3f77bd04303e51abe1356fd8c99bea969c2f0aff44e3-%E5%B9%BB%E7%81%AF%E7%89%87106.JPG),![幻灯片107.JPG](https://pic.leetcode-cn.com/b4b4d04c1b7cbe3bf4b2daab714a6dd1a1339187747da13771d041e0221e2cc2-%E5%B9%BB%E7%81%AF%E7%89%87107.JPG),![幻灯片108.JPG](https://pic.leetcode-cn.com/3d9947ab10625a4db356573b6d27a163f58b1b60055526d01633164081fa8706-%E5%B9%BB%E7%81%AF%E7%89%87108.JPG),![幻灯片109.JPG](https://pic.leetcode-cn.com/3239740fc70a30ae084c4164e07a0c91ca3b1f44bc570e8d32855a91cb22307b-%E5%B9%BB%E7%81%AF%E7%89%87109.JPG),![幻灯片110.JPG](https://pic.leetcode-cn.com/8fa5d39a60ec72ab4e70b01a03cdb147e45ba6c0e731d4a942329021b1d19c71-%E5%B9%BB%E7%81%AF%E7%89%87110.JPG),![幻灯片111.JPG](https://pic.leetcode-cn.com/90c2021002defdd0573380f52c47a769b1c0750e8916dce7d901737574eafd0c-%E5%B9%BB%E7%81%AF%E7%89%87111.JPG),![幻灯片112.JPG](https://pic.leetcode-cn.com/0235f10c771442a516dcf2e8b1f0df2ac577709b8c13d0dadd62f648021d168b-%E5%B9%BB%E7%81%AF%E7%89%87112.JPG)>

31题解决好了，下面的问题就是怎么调它、怎么保存结果，以及怎么判断是否已经达到最大值该停止循环了。尝试一下吧。

```python []
class Solution:
    def permute(self, nums):    
        nums.sort()
        is_max = 0#达到最大值
        res=[]
        res.append(nums[:])

        while is_max!=1:
            tem=[]
            a = self.nextPermutation(nums)
            if a==1:
                return res
            else:
                res.append(a[:])
        return res


    def nextPermutation(self,nums):#来自31题，改变了两个return
        is_max = 1
        r = 2 #从右边第二个数开始往左
        x=0 #列表中大于L值的数的索引
        while r<=len(nums):
            if nums[-r]<nums[-r+1]:
                is_max = 0
                for i in nums[-r+1:]:
                    if i > nums[-r]:#因为后面的数中每一次都是升序排列的结果，所以第一个比L值大的就是比L大的数中最小的
                        x=nums[-r+1:].index(i)-r+1
                    else:
                        break
                nums[-r],nums[x]=nums[x],nums[-r]#交换值
                nums[-r+1:]=sorted(nums[-r+1:])#升序排列后面的
                return nums #原来为break
            r+=1
        return is_max #原来为if is_max:
                            #nums.sort()
```


# 4.见缝插数——[22题](https://leetcode-cn.com/problems/generate-parentheses/)
我当时随意的写了第一个题解[见缝插括号](https://leetcode-cn.com/problems/generate-parentheses/solution/5xing-python-by-chun-meng-da-xiao-yang/)，当时主要是感叹那一种pythonic写法的简洁和巧妙，现在这一题又用上了它的思想，而且与前面两个算法相比，可以算是最简单易懂易实现的了。主要思想就是以第一个数为基准，在它的两边分别插入第二个数，将结果保存；再以刚刚的结果为基准，数的左右插入第三个数，以此类推即可得到所有的解。看gif比较好理解：
![9.gif](https://pic.leetcode-cn.com/1117356ac347f60b90f49f448fd47732dafebb9decbe7fef909f03f4f03b9a95-9.gif)

```python []
class Solution:
    def permute(self, nums): 
        res = [[nums[0]]]
        tem = []
        n = len(nums)
        for i in range(1,n):
            for k in res:
                for j in range(len(k)+1):
                    k.insert(j,nums[i])#在索引为j的位置插入元素
                    tem.append(k[:])
                    k.pop(j)#删除索引为j的元素
            res=tem
            tem=[]
        return res
```
```python []
class Solution:
    def permute(self, nums): 
        res = [[nums[0]]]
        tem = []
        n = len(nums)
        for i in range(1,n):
            res = [k[0:j]+[nums[i]]+k[j:] for k in res for j in range(len(k)+1)]
            tem=[]
            #占位
            #占位
            #占位
            #占位
            #占位
        return res
```
当然了，第一个程序用了3层循环，从时间复杂度的角度来说可能不友好，于是继续改写成第二种pythonic的写法咯，除去初始化的前3行，正儿八经for循环3行就搞定了你说牛b不牛b！再一次举一反三：**凡是类似第一种的3层循环都可以写成第二种!Got that?!**

# 总结
*`做题不是目的，目的是通过做题锻炼思维、掌握常用的算法。
——蠢萌哒小洋`*

不要做过了就忘了，要变成你自己的。

# 其他
如果有缘的话，大家也可以看到我在[其他一些题目下面写的题解](https://leetcode-cn.com/profile/articles/)，同样都是以`超强gif助你理解使用...`开头的，我坚信**能用图说明白的绝不用嘴BB**，而且图片更直观形象，动画能更好的反应程序是怎么执行的、某个变量如何获取、它下一步到哪去了等等。做gif还是挺耗时间和精力的，上面这三个就做了一下午，尤其第一个gif最耗时间，导致第2、3个都没怎么美化了。所以大家要是喜欢的话记得点赞或者关注，当然**有什么建议也可以评论**，我会听的！才怪😜

有童鞋问我gif是怎么做的，我用的是**1.激活版** **2.PowerPoint365/其他*最新版*PowerPoint**，两个条件缺一不可。然后用Gif录制工具录下来的。