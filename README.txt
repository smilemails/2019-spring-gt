----------演算法思路----------
1. 判斷input graph(G)是否為尤拉圖。若否則進行2，若是則直接進行5。
2. 找出所有degree為奇數的vertex。
3. 將奇數degree的vertex兩兩配對，計算其最短路徑長。
4. 重複3找出所有組合方式中，所需的最短路徑長的和最小的配對方式，並新增edge將其兩兩連接，得到尤拉圖(G')。
5. 在G'中找任一點vertex為參考點，並將此vertex新增到goal graph(C)中。
6. 在參考點上找一條不屬於C的edge，且除非別無選擇，此edge不能是G\E(C)中的bridge。
7. 將此條edge與另一端的vertex新增到C中，並指定另一端的vertex為新的參考點。
8. 重複6.7直到 sizeof(E(C)) = sizeof(E(G'))。此時C便是最佳path。

----------程式碼解釋----------
演算法思路中的 5~8 為子函數 Eularpath。
--其輸入為尤拉圖。
--輸出為此尤拉圖的尤拉路徑。

演算法思路中的 1~4 為子函數 EularGraph。
--其輸入為任意連通的圖。
--輸出為最佳尤拉化後的尤拉圖。
--為了確保最佳化，此處使用窮舉法計算所有配對方式所需的額外路徑長，並選擇其中最佳解。

子函數 degree。
--輸入為vertex。
--輸出為其degree。
--用來判斷每個vertex的degree。

最後將輸出存放在string Eulerpath(network_manager*)中。
並且在程式的最後執行cout。

----------BUG report----------

1. fake-mininet API 的 network_manager->interpret()無法接受輸入的vertex超過10個，即使更改預測的tablesize也不行。

2. 輸入vertex的名字必須是{a,b,c,d,e,f,g,h,i,j,k}中的元素，且必須按照順序。如b點的位置必須在vlist[1]，k點的位置必須在vlist[9]，不管有沒有其他點。

3. class path中尋找path的功能不完善，無法找出所有path。


----------補充----------
由於程式善未完全完成。
--此程式只能輸入無向圖。
--此程式目前只能輸入尤拉圖。
--且不能處理所有無向的尤拉圖。