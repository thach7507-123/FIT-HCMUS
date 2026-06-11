# BÁO CÁO ĐỒ ÁN THUẬT TOÁN SORT

## THÔNG TIN CHUNG
- **Tên môn học:** Cấu trúc Dữ liệu và Giải thuật
- **Thời gian học:** Học kỳ 2 - 2025-2026
- **Giáo viên giảng dạy, hướng dẫn:**
  1. Huỳnh Lâm Hải Đăng
  2. Phạm Trọng Nghĩa
  3. Nguyễn Thanh Tình 
  4. Nguyễn Ngọc Đức
- **Danh sách sinh viên nhóm thực hiện đồ án:**
  1. Nguyễn An Thạch MSSV: 25120435
  2. Trương Công Nhật MSSV: 25120405
  3. Trần Nhất Phong MSSV: 25120413

---

## 1. PHÂN TÍCH LẦN CHẠY ĐẦU TIÊN (LẦN 1)

### 1.1. Bài A - Integer Sort

- **Đặc điểm bài toán:** Yêu cầu sắp xếp một dãy gồm N số nguyên. Giới hạn (10s,1024MB) , 1 <= N <= 1e5 , giá trị −2^31≤ x ≤ 2^31−1 .
- **Thuật toán cài đặt tốt nhất ở lần 1:** Thuật toán Quick Sort phiên bản Đệ quy kết hợp kỹ thuật Median-of-Three và Insertion Sort.
- **Các phương thức tối ưu hóa:**
  - Tối ưu hóa việc chọn pivot : Lấy trung vị của 3 phần tử (Đầu, Giữa, Cuối) để làm chốt. Kỹ thuật này giúp thuật toán né được trường hợp xấu nhất O(N^2) khi đối mặt với các test case mảng đã được sắp xếp sẵn hoặc sắp xếp giảm dần.
  - Kỹ thuật Ngưỡng giới hạn : Thiết lập một ngưỡng an toàn (`right - left <= 15`). Khi mảng được chẻ nhỏ xuống dưới 15 phần tử, thuật toán tự động dừng gọi đệ quy và chuyển sang dùng Insertion Sort. Với các mảng nhỏ, Insertion Sort vượt trội hơn hẳn Quick Sort do hằng số tính toán cực kỳ thấp.
  - Fast I/O: Sử dụng `ios::sync_with_stdio(false);` và `cin.tie(nullptr);` để mở khóa tốc độ đọc/ghi dữ liệu tối đa của C++.
- **Lý giải lựa chọn thuật toán:**
  - Bản code này cân bằng giữa hiệu năng và tính dễ đọc bằng cách kết hợp Quick Sort với Insertion Sort. Các mảng con nhỏ sẽ không tiếp tục đệ quy để tránh cây đệ quy quá sâu và giảm tốn bộ nhớ Stack. Nhờ tận dụng khả năng phân hoạch nhanh của Quick Sort và tốc độ xử lý tốt trên mảng nhỏ của Insertion Sort, thuật toán đạt hiệu năng thực tế ổn định gần $O(N \log N)$.
### 1.2. Bài B - Lexicographic Sort

- **Đặc điểm bài toán:** Sắp xếp chuỗi đơn thuần theo thứ tự từ điển.
  Giới hạn thời gian rộng (10s), bộ nhớ lớn (1024 MB), số lượng chuỗi lớn N <= 10000, độ dài 10 - 100.
- **Thuật toán cài đặt:** Kết hợp Bucket Sort (phân nhóm theo 2 ký tự đầu) và Iterative
  QuickSort (sắp xếp không đệ quy) có kết hợp với Insertion Sort. Quản lý hoàn toàn thông qua mảng chỉ số (idx).
- **Các phương thức tối ưu hóa:**
  - Phân nhóm (Bucket Sort): Tiền xử lý bằng cách chia các chuỗi vào 676 bucket dựa trên giá trị của 2 ký tự đầu tiên. Điều này giúp chia nhỏ mảng $10^5$ phần tử thành các mảng rất nhỏ để xử lý độc lập, giảm thiểu đáng kể số lần gọi hàm sắp xếp
  - Quản lý bộ nhớ gián tiếp: Thuật toán không bao giờ hoán vị trực tiếp các chuỗi string. Thay vào đó, nó hoán đổi các số nguyên trong mảng idx có chi phí $O(1)$. Các thao tác chèn cũng chỉ làm việc trên mảng idx
  - Khử đệ quy (Iterative QuickSort): Sử dụng hai mảng stack_left và stack_right giả lập bộ nhớ stack để khử đệ quy. Kỹ thuật này loại bỏ chi phí gọi hàm (overhead) và rủi ro tràn bộ nhớ stack.
  - Tối ưu chọn Pivot (Median-of-three): Chốt (pivot) được chọn ở vị trí giữa và được sắp xếp trước với hai phần tử đầu/cuối của mảng con. Điều này triệt tiêu rủi ro mảng bị phân hoạch mất cân bằng.
  - Tối ưu mảng nhỏ: Khi mảng con có kích thước $\le 15$, thuật toán tự động ngắt QuickSort và chuyển sang Insertion Sort  vì thuật toán này chạy nhanh hơn rất nhiều do chi phí hằng số thấp trên các mảng nhỏ.
  - Fast I/O: Tăng tốc I/O qua ios::sync_with_stdio(false) và cin.tie(nullptr).

- **Lý giải lựa chọn thuật toán:**
  - Việc phân nhóm 2 ký tự đầu hoạt động như một bước radix sort, triệt tiêu việc phải so sánh sâu toàn bộ $10^5$ chuỗi. Thao tác hoán vị gián tiếp bằng mảng chỉ số idx loại bỏ hoàn toàn "nút thắt cổ chai" do việc cấp phát và di chuyển bộ nhớ của thư viện <string>. Việc tự triển khai hệ thống quản lý stack cho QuickSort đẩy tốc độ và sự ổn định của chương trình lên mức tối đa để vượt qua các bộ test hiệu năng khắt khe.

### 1.3. Bài C - Length-aware Lexicographic String Sort 
- **Đặc điểm bài toán:** Ưu tiên sắp xếp theo độ dài chuỗi trước, nếu độ dài bằng nhau mới xét thứ tự từ điển. Giới hạn  (1s, 256 MB).
- **Thuật toán cài đặt tốt nhất ở lần 1:** Bài C sử dụng thuật toán Randomized QuickSort kết hợp sử dụng mảng con trỏ.
- **Các phương thức tối ưu hóa:**
  - Tối ưu hoá việc chọn pivot: Sử dụng hàm rand() để tiến hành chọn pivot 1 cách ngẫu nhiên, theo mặt xác suất toán học gần như loại bỏ hoàn toàn rơi vào trường hợp tệ nhất.
  - Tối ưu hoán vị: Đổi địa chỉ con trỏ (chi phí O(1)) thay vì sao chép từng ký tự của chuỗi (chi phí O(L)).
  - Kỹ thuật Thoát sớm: Hàm so sánh trả về kết quả ngay khi thấy độ dài chuỗi khác nhau, không cần duyệt tiếp các ký tự.
  - Fast I/O: Sử dụng ios_base::sync_with_stdio(false); và cin.tie(NULL); để tăng tốc độ đọc/ghi dữ liệu tối đa.
- **Lý giải lựa chọn thuật toán:**
  - Về việc chọn thuật toán Randomize QuickSort: Bằng cách dùng hàm rand() để chọn một vị trí ngẫu nhiên làm chốt, bạn dựa vào xác suất toán học để chia đều mảng. Xác suất để rand() liên tục bốc trúng phần tử tệ nhất trong hàng chục ngàn lần lặp là vô cùng nhỏ (gần như bằng 0). Nhờ đó, thời gian chạy thực tế luôn được giữ ổn định ở mức $O(N \log N)$.

---

## 2. CÁCH THỨC SINH TEST CASE (`test_gen.cpp`)

## Bài A - Integer Sort


### 2.1. Cấu trúc và logic sinh test case

  - **Test001.in - Ngẫu nhiên hoàn toàn:** Các giá trị được phân phối đều từ âm vô cùng `-2147483648` đến dương vô cùng `2147483647`.
  - **Test002.in - Tăng dần rồi giảm dần:** Mảng có cấu trúc tăng dần các số chẵn từ đầu đến giữa mảng, và giảm dần từ giữa về cuối mảng.
  - **Test003.in - Cấu trúc Anti-Merge:** Mảng được sinh thông qua hàm đệ quy `generate_anti_merge()`, cố tình sắp xếp đan xen các phần tử chẵn/lẻ ở mọi phân đoạn để tối đa hóa số lần hoán đổi chéo.
  - **Test004.in - Đã sắp xếp hoàn toàn:** Mảng đã được sắp xếp tăng dần tuyệt đối.
  - **Test005.in - Trùng lặp cực lớn:** Mảng chứa cực kỳ nhiều giá trị trùng lặp, chỉ xoay vòng lặp lại ngẫu nhiên đúng 3 giá trị: `INT_MIN`, `0`, và `INT_MAX`.

### 2.2. Thuật toán mục tiêu
-   **Quick Sort cơ bản :** Sử dụng chốt là phần tử đầu, phần tử cuối, hoặc phần tử ở chính giữa.
-   **Quick Sort thiếu tối ưu:** Các phiên bản không có cơ chế phân hoạch 3 ngã .
-   **Merge Sort:** Thuật toán nổi tiếng với sự ổn định.
-   **Heap Sort:** Thuật toán dựa trên cấu trúc cây nhị phân.
### 2.3. Lý giải việc chọn thuật toán và tác dụng của Test
- **Lý do chọn thuật toán mục tiêu:** Nhắm vào các thuật toán chưa có khả năng tối ưu hóa mã nguồn và tính ứng biến của thuật toán trước các dữ liệu bất lợi .

- **Tại sao test case lại làm tăng thời gian chạy:**
  * **Test001.in:** Không mang tính chất gài bẫy. Test này đóng vai trò làm thước đo chuẩn để đánh giá tốc độ thực tế  của mọi thuật toán trong điều kiện dữ liệu lý tưởng nhất.
  * **Test002.in:** Nhắm vào các phiên bản **Quick Sort chọn chốt ở giữa** hoặc các chiến lược chọn chốt thiếu ổn định. Cấu trúc mảng tăng dần rồi giảm dần tạo ra các phân hoạch mất cân bằng đáng kể trong nhiều bước đệ quy, khiến Quick Sort khó chia mảng thành hai nửa đều nhau như trên dữ liệu ngẫu nhiên. Điều này làm số lần gọi đệ quy và chi phí phân hoạch tăng lên rõ rệt, từ đó làm suy giảm hiệu năng thực tế của thuật toán.
  * **Test003.in:** Nhắm vào **Merge Sort**. Mảng được sinh bằng hàm đệ quy `generate_anti_merge()`, chia xen kẽ các phần tử vào hai nửa con ở mọi tầng đệ quy. Cấu trúc này khiến quá trình `merge` ở mỗi mức phải thực hiện gần như tối đa số phép so sánh giữa hai mảng con, làm tăng đáng kể hằng số thời gian thực thi của Merge Sort.

  * **Test004.in:**
    -   Nhắm vào **Quick Sort chọn chốt ở đầu hoặc cuối**: Với mảng đã được sắp xếp tăng dần hoàn toàn, các phiên bản Quick Sort kiểu này sẽ liên tục chia mảng thành hai phần có kích thước `0` và `N-1`, khiến cây đệ quy trở nên cực kỳ mất cân bằng và đẩy độ phức tạp lên gần `O(N^2)`.
    -   Đồng thời tạo áp lực lên **Heap Sort**: Khi xây dựng Max-Heap từ mảng tăng dần, nhiều phần tử nhỏ nằm gần phía trên cây sẽ phải thực hiện các thao tác `sift-down` dài để khôi phục cấu trúc Heap, làm tăng chi phí thực thi thực tế.

  * **Test005.in:** Nhắm vào các phiên bản **Quick Sort không sử dụng phân hoạch 3 ngã **. Khi mảng chứa số lượng cực lớn các giá trị trùng lặp, thuật toán sẽ liên tục thực hiện nhiều phép so sánh và hoán đổi không cần thiết giữa các phần tử bằng nhau. Điều này làm giảm hiệu quả phân hoạch, gia tăng độ sâu đệ quy và khiến thời gian thực thi suy giảm đáng kể.
---




## Bài B - Lexicographic Sort

### 2.1. Cấu trúc và logic sinh test case
Mã trong test_gen.cpp được thiết kế để sinh dữ liệu bao phủ cả các trường hợp tổng quát (average cases) lẫn các trường hợp đặc biệt (edge/worst cases). Các test case được tạo dựa trên 5 kịch bản logic chính:

**Logic sinh test case cho bài B - Lexicographic Sort:**
  - **Test001.in - Trùng lặp hoàn toàn:** Toàn bộ dữ liệu được sinh ra đều có cùng một giá trị giống hệt nhau.
  - **Test002.in - Đột biến nhỏ:** Các phần tử hoặc chuỗi gần như giống hệt nhau có các sai khác nhỏ ở duy nhất một ký tự ở cuối.
  - **Test003.in - Sắp xếp ngược (Worst-case):** Dữ liệu được tạo theo quy luật sắp xếp hoàn toàn theo thứ tự ngược lại, mảng giảm dần nghiêm ngặt.
  - **Test004.in - Ngẫu nhiên có giới hạn (Độ đa dạng thấp):** Dữ liệu được xáo trộn ngẫu nhiên nhưng chỉ cấu thành từ một tập hợp chỉ có 2 ký tự, mảng chỉ gồm các ký tự a và b.
  - **Test005.in - Ngẫu nhiên hoàn toàn:** Các phần tử được sinh ngẫu nhiên tự do trên toàn bộ miền giá trị, từ ký tự 'a' đến 'z' để kiểm tra tính đúng đắn tổng quát.

### 2.2. Thuật toán mục tiêu

**Các thuật toán mục tiêu mà bộ test này nhắm tới để đánh giá và thử thách hiệu năng bao gồm:**
  - **QuickSort cơ bản** (sử dụng phân hoạch Lomuto hoặc Hoare với pivot cố định).
  - **Radix Sort (MSD)** hoặc các thuật toán/hàm so sánh chuỗi ký tự theo cấu trúc từ điển.
  - **Các thuật toán sắp xếp ngây thơ có độ phức tạp $O(N^2)$** (Insertion Sort, Bubble Sort).
  - **Các thuật toán tối ưu chuẩn hóa** (MergeSort, HeapSort, Introsort) dùng làm mốc so sánh.

### 2.3. Lý giải việc chọn thuật toán và tác dụng của Test
- **Lý do chọn thuật toán mục tiêu:** Nhắm vào các thuật toán phổ biến nhưng tồn tại các điểm yếu chí mạng trong
  thiết kế (như cách chọn pivot cố định, cách phân hoạch khi có khóa trùng, hoặc chi phí duyệt chuỗi) nhằm kiểm tra
  khả năng tối ưu hóa mã nguồn và tính ứng biến của thuật toán trước các dữ liệu bất lợi (Worst-case).

- **Tại sao test case lại làm tăng thời gian chạy:**
  * **Test001.in & Test004.in:** Việc dữ liệu trùng lặp hoàn toàn hoặc có độ đa dạng thấp khiến
  QuickSort cơ bản không thể chia đều mảng. Nó liên tục phân hoạch thành hai mảng con mất cân bằng
  nghiêm trọng (kích thước $0$ và $N-1$), đẩy độ phức tạp từ $O(N \log N)$ xuống $O(N^2)$ và dễ gây tràn bộ nhớ stack (Stack Overflow).
  * **Test002.in:** Ép các thuật toán so sánh chuỗi hoặc Radix Sort (MSD) phải duyệt qua toàn bộ chiều dài của chuỗi (đến tận ký tự cuối cùng)
  mới tìm ra điểm khác biệt. Chi phí cho một phép so sánh bị đẩy lên mức tối đa $O(L)$ với $L$ là độ dài chuỗi, làm chậm đáng kể tiến trình tổng thể.
  * **Test003.in:** Tạo ra mảng giảm dần nghiêm ngặt. Đây là trạng thái tồi tệ nhất đối với Insertion Sort và Bubble Sort
  khi buộc chúng phải thực hiện tối đa số phép hoán vị và dời chỗ ($O(N^2)$). Đồng thời, nó cũng làm phân hoạch của QuickSort (pivot đầu/cuối) bị lệch hoàn toàn.
  * **Test005.in:** Đóng vai trò làm bài kiểm tra nền tảng (Baseline test) để xác định xem thuật toán
  có đạt được độ phức tạp kỳ vọng trong trường hợp trung bình (Average-case) là $O(N \log N)$ hay không.

---

## Bài C - String Length and Lexicographic Sort

### 2.1. Cấu trúc và logic sinh test case

Mã trong `test_gen.cpp` (hàm `gen_strlenlexi`) được thiết kế tinh vi để sinh ra các tập dữ liệu mảng chuỗi với quy mô lớn ($N = 10,000$). Khác với việc sắp xếp số nguyên, bộ test này tập trung khai thác điểm yếu chí mạng của các template code thủ công trong việc xử lý **chi phí so sánh chuỗi ($O(L)$)**, bẫy phân mảnh bộ nhớ và các trường hợp suy thoái cây đệ quy. Các test case được tạo dựa trên 5 kịch bản logic chính:

* **Test001.in - Longest Common Prefix (Tiền tố chung cực dài):** Toàn bộ $10,000$ chuỗi đều đạt độ dài tối đa 100. 99 ký tự đầu tiên của tất cả các chuỗi giống hệt nhau (toàn bộ là `a`), sự khác biệt duy nhất nằm ở ký tự thứ 100 được sinh ngẫu nhiên.
* **Test002.in - Massive Duplicates (Bùng nổ chuỗi trùng lặp):** Mảng chứa $10,000$ phần tử nhưng chỉ có đúng 3 chuỗi duy nhất xuất hiện (với độ dài 100). Ba chuỗi này được lặp đi lặp lại và xáo trộn ngẫu nhiên liên tục.
* **Test003.in - MSD Radix Sort Trap (Bẫy phân mảnh MSD):** Các chuỗi có độ dài 100, trong đó 4 ký tự đầu tiên liên tục thay đổi để phân bổ đều khắp 26 chữ cái, nhưng 96 ký tự phía sau lại bị ép cho giống hệt nhau (toàn `a`).
* **Test004.in - Reverse Sorted Anti-Pivot (Nghịch đảo thứ tự):** Mảng chứa $10,000$ chuỗi ngẫu nhiên (độ dài 100) đã được sắp xếp **nghịch biến** (ngược lại hoàn toàn với yêu cầu của bài toán: ưu tiên chuỗi dài lên trước, sau đó từ điển giảm dần).
* **Test005.in - Length-Boundary Edge Case (Sự giao thoa độ dài):** Các chuỗi có độ dài dao động liên tục từ 10 đến 100. Tuy nhiên, nội dung các chuỗi đều chia sẻ chung một chuỗi gốc tuần hoàn (`abcdef...`), chỉ khác nhau ở độ dài bị cắt và một ký tự ngẫu nhiên ở cuối.

---

### 2.2. Thuật toán mục tiêu

Các thuật toán mục tiêu mà bộ test này nhắm tới để triệt tiêu hiệu năng bao gồm:

* **Quick Sort thủ công:** Đặc biệt là các bản code không sử dụng kỹ thuật phân hoạch 3 chiều (3-way partitioning / Dutch National Flag) hoặc sử dụng chốt (pivot) cố định.
* **Radix Sort thủ công:** Bao gồm cả hệ thống phân nhánh từ đầu đến cuối (MSD - Most Significant Digit) và sắp xếp từ cuối lên đầu cần đệm chuỗi (LSD - Least Significant Digit).
* **Hàm so sánh (Comparator) kém tối ưu:** Nhắm vào các hàm viết gộp chung tiêu chí độ dài và từ điển nhưng không tối ưu hóa luồng rẽ nhánh logic.
---

### 2.3. Lý giải việc chọn thuật toán và tác dụng của Test

**Lý do chọn thuật toán mục tiêu** Trong lập trình thi đấu, thí sinh thường tự implement Quick Sort hoặc Radix Sort để vượt qua các bài toán về chuỗi. Mặc dù lý thuyết chúng chạy rất nhanh, nhưng các code template này cực kỳ dễ bị sụp đổ (Time Limit Exceeded) khi gặp các edge case (trường hợp biên) làm thay đổi bản chất luồng đệ quy hoặc phân bổ bộ nhớ.

**Tại sao test case lại làm giảm cực độ thời gian chạy?**

* **Test001.in:** Việc các chuỗi giống hệt nhau ở 99 ký tự đầu ép mọi phép toán so sánh `stringA < stringB` phải chạy vòng lặp xuyên qua toàn bộ độ dài chuỗi ($O(L)$). Kể cả `std::sort` cũng bị đẩy tổng thời gian lên ngưỡng $O(N \log N \times L)$, bào mòn giới hạn thời gian 1 giây một cách tàn nhẫn.
* **Test002.in:** Quick Sort cơ bản (2-way partitioning) khi gặp mảng chứa hàng ngàn phần tử trùng lặp sẽ liên tục hoán vị và rẽ nhánh sai lệch. Điều này khiến cây đệ quy bị mất cân bằng trầm trọng, sụp đổ độ phức tạp từ $O(N \log N)$ xuống mức tồi tệ nhất là $O(N^2)$.
* **Test003.in:** Đánh trúng tử huyệt của thuật toán MSD Radix Sort. Việc chia nhánh quá rộng ở 4 ký tự đầu tạo ra hàng nghìn "bucket" (xô) trống rỗng. Thuật toán vẫn phải cấp phát bộ nhớ và gọi đệ quy liên tục cho các bucket chỉ chứa 1 phần tử, tạo ra lượng hao phí tài nguyên (cache miss và overhead) khổng lồ.
* **Test004.in:** Một "cái tát" trực diện vào những lập trình viên chọn pivot cho Quick Sort bằng phần tử đầu, cuối hoặc giữa mà quên bước ngẫu nhiên hóa (randomize). Với mảng sắp xếp ngược, Quick Sort sẽ luôn chia mảng thành một bên $0$ phần tử và một bên $N-1$ phần tử, lập tức đẩy thời gian chạy lên $O(N^2)$.
* **Test005.in:** Khai thác lỗ hổng trong Radix Sort LSD. Để sắp xếp các chuỗi lệch độ dài (từ 10 đến 100), LSD thường phải thêm "ký tự ảo" (padding) vào các chuỗi ngắn cho bằng chuỗi dài nhất. Với sự chênh lệch lớn thế này, thuật toán sẽ thực hiện tới hàng chục nghìn phép toán vô nghĩa quét qua các vùng nhớ ảo, gây lãng phí năng lực xử lý trầm trọng.
---

## 3. PHÂN TÍCH LẦN CHẠY THỨ HAI (LẦN 2)

## Bài A - Integer Sort

### 3.1. Thuật toán và phương thức tối ưu hóa


- **Thuật toán cài đặt tốt nhất:** IntroSort tối ưu hóa thủ công .

- **Các phương thức tối ưu hóa liên quan:**
    - Chuyển từ Quick Sort thuần sang **IntroSort** để tránh trường hợp xấu `O(N^2)`.
    - Áp dụng **Heap Sort fallback** khi độ sâu đệ quy vượt giới hạn.
    - Sử dụng **Median-of-Three Pivot Selection** để chọn chốt ổn định hơn.
    - Thay phân hoạch kiểu cũ bằng **Hoare Partition** nhằm giảm số phép hoán đổi.
    - Áp dụng **Tail Recursion Optimization**: luôn đệ quy vào đoạn nhỏ hơn trước để giảm số lời gọi hàm và độ sâu stack.
    - Tăng ngưỡng chuyển sang **Insertion Sort** từ `15` lên `24` để tối ưu cho các đoạn nhỏ.
    - Thực hiện **Final Insertion Sort** trên toàn mảng sau khi phân hoạch gần hoàn tất nhằm tận dụng tính chất “gần được sắp xếp”.
    - Sử dụng `inline` cho các hàm nhỏ (`swap_`, `insertion_sort`, `sift_down`) để giảm chi phí gọi hàm.
    - Dùng `__lg(n)` thay cho `log2(n)` để tính giới hạn độ sâu nhanh hơn.

### 3.2. Cách thức tiếp tục tối ưu so với Lần 1


Ở lần chạy đầu tiên, thuật toán sử dụng Quick Sort kết hợp Insertion Sort cho các đoạn nhỏ. Dù đã dùng Median-of-Three để chọn chốt, thuật toán vẫn tồn tại một số điểm nghẽn hiệu năng:

- Đệ quy trên cả hai nhánh làm tăng số lượng function call và gây áp lực lên stack.
- Partition kiểu cũ tạo ra nhiều phép hoán đổi không cần thiết.
- Quick Sort thuần vẫn có nguy cơ gặp trường hợp phân hoạch xấu trên các test được thiết kế đặc biệt.
- Insertion Sort được gọi nhiều lần trên các đoạn nhỏ riêng lẻ, chưa tận dụng được tính chất “gần sorted” của toàn bộ mảng ở giai đoạn cuối.

Ở lần tối ưu thứ hai, các điểm nghẽn trên được xử lý bằng cách chuyển sang mô hình IntroSort:

- Khi độ sâu đệ quy vượt ngưỡng `2 * __lg(n)`, thuật toán tự động chuyển sang Heap Sort để bảo đảm độ phức tạp xấu nhất chỉ còn `O(N log N)`.
- Tail Recursion Optimization giúp giảm mạnh số lời gọi hàm đệ quy.
- Hoare Partition giảm số lần swap và cải thiện locality của cache CPU.
- Final Insertion Sort được thực hiện đúng một lần ở cuối, giúp tối ưu mạnh trên các đoạn đã gần có thứ tự.
- Các hàm nhỏ được `inline` để giảm overhead ở mức instruction-level.

## Bài B - Lexicographic Sort
### 3.1. Thuật toán và phương thức tối ưu hóa

- **Thuật toán cài đặt tốt nhất:** Khởi tạo phân lô theo cơ số 2 ký tự đầu (MSD Radix Sort / Bucket Sort) kết hợp Quicksort không đệ quy (Iterative Quick Sort) trên mảng chỉ số và Fallback về Insertion Sort.
- **Các phương thức tối ưu hóa liên quan:**
    - **Sắp xếp gián tiếp (Indirect Sorting):** Sử dụng mảng chỉ số phụ `idx` để tránh chi phí deep copy và di chuyển cấu trúc `string` cồng kềnh trực tiếp trong bộ nhớ.
    - **Phân lô dữ liệu (Bucket Sort):** Phân chia mảng thành $26 \times 26 = 676$ buckets độc lập dựa trên tiền tố 2 ký tự đầu để thu hẹp không gian phân hoạch.
    - **Khử đệ quy (Iterative Quick Sort):** Sử dụng cấu trúc ngăn xếp mảng thủ công `stack_left` và `stack_right` thay cho call stack hệ thống nhằm kiểm soát bộ nhớ tuyệt đối.
    - **Sử dụng `Median-of-Three` Pivot Selection** để chọn chốt ổn định hơn, giảm thiểu nguy cơ rơi vào trường hợp xấu nhất $O(N^2)$.
    - **Ngưỡng chuyển đổi sang Insertion Sort:** Giới hạn phân đoạn kích thước nhỏ (`right - left <= 15`) để lập tức chuyển sang sắp xếp chèn, tận dụng tính chất cache locality của CPU.
    - **Tối ưu I/O:** Sử dụng `ios::sync_with_stdio(false)` và `cin.tie(nullptr)` nhằm tăng tốc độ đọc ghi dữ liệu từ luồng chuẩn.

### 3.2. Cách thức tiếp tục tối ưu so với Lần 1

Ở lần chạy đầu tiên, thuật toán xử lý trực tiếp trên tập hợp chuỗi lớn, dẫn đến việc lặp lại nhiều phép so sánh không cần thiết đối với các chuỗi có chung tiền tố kéo dài. Thuật toán vẫn tồn tại một số điểm nghẽn hiệu năng:

- Quicksort thuần có nguy cơ cao gặp trường hợp phân hoạch xấu trên các test được thiết kế đặc biệt.
- Chi phí thao tác hoán đổi và xử lý trực tiếp trên các đối tượng `std::string` làm giảm tốc độ thực thi đáng kể.
- Việc kiểm soát các bucket đứng độc lập hoặc rỗng chưa được phân luồng tối ưu, gây lãng phí chu kỳ CPU.
- Tiền tố của các chuỗi chưa được tận dụng để cắt giảm số lần so sánh ký tự ở các bước phân hoạch sâu.

Ở lần tối ưu thứ hai, các điểm nghẽn trên được xử lý triệt để bằng cách chuyển sang mô hình kết hợp MSD Radix và Khử đệ quy gián tiếp:

- Việc băm trước mã định danh bucket cho 2 ký tự đầu giúp thuật toán lược bỏ hoàn toàn các phép so sánh ký tự tiền tố này trong suốt quá trình phân hoạch sau đó.
- Áp dụng mảng gián tiếp phụ `temp_idx` để chốt vị trí tĩnh, đưa toàn bộ thao tác hoán đổi trong Quick Sort về xử lý số nguyên (`int`), triệt tiêu chi phí overhead bộ nhớ.
- Chỉ thực hiện kích hoạt vòng lặp sắp xếp cho các phân đoạn thực sự có va chạm (`bucket_count[i] > 1`), loại bỏ hàng ngàn lần gọi hàm vô tính chất.
- Cấu trúc vòng lặp `while` kết hợp ngăn xếp mảng thủ công giúp triệt tiêu hoàn toàn nguy cơ lỗi tràn bộ nhớ (Stack Overflow) dưới áp lực của các tập test case lớn.

## Bài C - Length-aware Lexicographic String Sort

### 3.1. Thuật toán và phương thức tối ưu hóa

**Thuật toán cài đặt tốt nhất:** Bucket/Counting Sort (theo chiều dài) kết hợp Iterative Quick Sort (gián tiếp) và Insertion Sort.

**Các phương thức tối ưu hóa liên quan:**
* Sử dụng **Bucket Sort / Counting Sort** ở vòng ngoài để phân nhóm chuỗi theo chiều dài với độ phức tạp `O(N)`, loại bỏ việc phải kiểm tra chiều dài khi so sánh.
* Áp dụng **Indirect Sorting (Sắp xếp gián tiếp)** qua mảng chỉ số `idx` thay vì hoán đổi dữ liệu thật, đưa chi phí hoán vị (swap) chuỗi từ `O(L)` về `O(1)`.
* Chuyển từ đệ quy sang **Iterative Quick Sort** bằng mảng stack thủ công (`stack_left`, `stack_right`) để loại bỏ hoàn toàn nguy cơ tràn bộ nhớ stack.
* Áp dụng **Hybrid Sort / Fallback**: Tự động chuyển sang **Insertion Sort** khi kích thước mảng con cần phân hoạch đạt ngưỡng nhỏ (`<= 15`) để tối ưu hằng số thời gian.
* Sử dụng mảng 1 chiều toàn cục (Global arrays) cấp phát tĩnh (`arr`, `idx`, `temp_idx`) với hằng số `MAXN` để tránh overhead của cấp phát bộ nhớ động rải rác.
* Trích xuất độ dài chuỗi `.length()` đúng một lần trong pha nhập dữ liệu để đếm xô, không lặp lại thao tác này.
* Tối ưu I/O cơ bản ở mức hệ thống bằng `ios::sync_with_stdio(false)` và `cin.tie(nullptr)`.

### 3.2. Cách thức tiếp tục tối ưu so với Lần 1

Ở lần chạy đầu tiên, thuật toán sử dụng Quick Sort đệ quy thuần túy trên mảng con trỏ ký tự `char**`. Thuật toán vẫn tồn tại các điểm nghẽn hiệu năng nghiêm trọng:

* Hàm so sánh gọi lại `strlen()` cho cả hai chuỗi ở *mỗi* bước phân hoạch, tạo ra một bottleneck tốn kém `O(L)` lặp đi lặp lại hàng chục ngàn lần.
* Đệ quy trên cả hai nhánh của Quick Sort làm tăng số lượng function call, gây áp lực lớn lên Call Stack và có nguy cơ Runtime Error.
* Quick Sort phải gánh vác việc sắp xếp toàn bộ tập dữ liệu lộn xộn với các độ dài ngắn khác nhau cùng một lúc.
* Quá trình cấp phát và giải phóng bộ nhớ thủ công (`new`, `delete`) cho từng chuỗi riêng biệt gây tốn chi phí thời gian và làm phân mảnh bộ nhớ.

Ở lần tối ưu thứ hai, các điểm nghẽn trên được xử lý triệt để bằng việc thiết kế lại luồng thực thi:

* Việc phân loại độ dài được tách riêng vào pha Counting Sort ban đầu. Chiều dài chuỗi chỉ được tính đúng 1 lần, triệt tiêu hoàn toàn chi phí đếm độ dài dư thừa ở các bước sau.
* Sự cồng kềnh khi thao tác trên mảng chuỗi được giải quyết bằng việc giữ nguyên cấu trúc mảng gốc `arr` và chỉ thực hiện swap trên các số nguyên của mảng `idx`.
* Iterative Quick Sort bằng mảng Stack kết hợp vòng lặp `while` giúp loại bỏ triệt để số lời gọi hàm đệ quy.
* Bài toán được chia nhỏ hiệu quả: Quick Sort giờ đây chỉ thực thi giới hạn trong các nhóm chứa chuỗi có *cùng chiều dài*, kết hợp với fallback linh hoạt sang Insertion Sort cho các nhóm nhỏ.
