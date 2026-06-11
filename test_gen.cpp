#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <climits>
using namespace std;

random_device rd;
mt19937 rng(rd());

void generate_anti_merge(vector<int>& a) {
    if (a.size() <= 1) return;

    vector<int> left, right;
    
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == 0) left.push_back(a[i]);
        else right.push_back(a[i]);
    }

    generate_anti_merge(left);
    generate_anti_merge(right);

    for (int i = 0; i < left.size(); i++) a[i] = left[i];
    for (int i = 0; i < right.size(); i++) a[i + left.size()] = right[i];
}

void gen_int(int test_id) {
    int n = 100000;

    if (test_id == 1) {
        cout << n << "\n";
        vector<int> a(n);
        uniform_int_distribution<int> dist(-2147483648, 2147483647);
        for (int i = 0; i < n; i++) {
            a[i] = dist(rng);
        }
        for (int i = 0; i < n; i++) cout << a[i] << "\n";
    } 
    else if (test_id == 2) {
        cout << n << "\n";
        vector<int> a(n);
        for (int i = 0; i < n / 2; i++) a[i] = i * 2;
        for (int i = n / 2; i < n; i++) a[i] = (n - i) * 2;
        for (int i = 0; i < n; i++) cout << a[i] << "\n";
    }
    else if (test_id == 3) {
        cout << n << "\n";
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1; 
        }
        generate_anti_merge(a); 
        for (int i = 0; i < n; i++) {
            cout << a[i] << "\n";
        }
    }
    else if (test_id == 4) {
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\n";
        }
    }
    else if (test_id == 5) {
        cout << n << "\n";
        uniform_int_distribution<int> flag_dist(1, 3);
        for (int i = 0; i < n; i++) {
            int random_choice = flag_dist(rng);
            if (random_choice == 1) cout << INT_MIN << "\n";
            else if (random_choice == 2) cout << 0 << "\n";
            else cout << INT_MAX << "\n";
        }
    }
}

void gen_strlexi(int test_id) {
    int n = 100000;
    uniform_int_distribution<int> char_dist(0, 25);

    if (test_id == 1) {
        cout << n << "\n";
        string pattern = "phungthanhdocaobang";
        string out = "";
        while (out.length() < 100) out += pattern;
        out = out.substr(0, 100); 
        for (int i = 0; i < n; i++) cout << out << "\n";
    }
    else if (test_id == 2) {
        cout << n << "\n";
        string pattern = "phungthanhdocaobang";
        string base_str = "";
        while (base_str.length() < 100) base_str += pattern;
        base_str = base_str.substr(0, 100);
        for (int i = 0; i < n; i++) {
            string current_str = base_str;
            current_str[98] = (char)('a' + char_dist(rng));
            current_str[99] = (char)('a' + char_dist(rng));
            cout << current_str << "\n";
        }
    }
    else if (test_id == 3) {
        cout << n << "\n";
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < 100; j++) s += (char)('a' + char_dist(rng));
            a[i] = s;
        }
        sort(a.begin(), a.end(), greater<string>());
        for (int i = 0; i < n; i++) cout << a[i] << "\n";
    }
    else if (test_id == 4) {
        cout << n << "\n";
        uniform_int_distribution<int> diff_dist(0, 99);
        uniform_int_distribution<int> pos_dist(0, 99);
        for (int i = 0; i < n; i++) {
            string s(100, 'a'); 
            int numsDiff = diff_dist(rng);
            for (int j = 0; j < numsDiff; j++) {
                int ranPos = pos_dist(rng);
                s[ranPos] = 'b';
            }
            cout << s << "\n";
        }
    }
    else if (test_id == 5) {
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < 100; j++) s += (char)('a' + char_dist(rng));
            cout << s << "\n";
        }
    }
}

void gen_strlenlexi(int test_id) {
    int n = 10000; 
    cout << n << "\n";
    uniform_int_distribution<int> char_dist(0, 25);
    if (test_id == 1) {
        for (int i = 0; i < n; i++) {
            string s(99, 'a');
            s += (char)('a' + char_dist(rng));
            cout << s << "\n";
        }
    } 
    else if (test_id == 2) {
        string s1(100, 'x');
        string s2(100, 'y');
        string s3(100, 'z');
        uniform_int_distribution<int> choice_dist(1, 3);
        
        for (int i = 0; i < n; i++) {
            int c = choice_dist(rng);
            if (c == 1) cout << s1 << "\n";
            else if (c == 2) cout << s2 << "\n";
            else cout << s3 << "\n";
        }
    } 
    else if (test_id == 3) {
        for (int i = 0; i < n; i++) {
            string s = "";
            int temp = i;
            for(int j = 0; j < 4; j++) {
                s += (char)('a' + (temp % 26));
                temp /= 26;
            }
            s += string(96, 'a'); 
            cout << s << "\n";
        }
    } 
    else if (test_id == 4) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < 100; j++) s += (char)('a' + char_dist(rng));
            a[i] = s;
        }
        sort(a.begin(), a.end(), [](const string& x, const string& y) {
            if (x.length() != y.length()) return x.length() > y.length();
            return x > y;
        });
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << "\n";
        }
    } 
    else if (test_id == 5) {
        string base_str = "";
        for(int j = 0; j < 100; j++) {
            base_str += (char)('a' + (j % 26)); 
        }
        
        for (int i = 0; i < n; i++) {
            int len = 10 + (i % 91); 
            string s = base_str.substr(0, len - 1);
            s += (char)('a' + char_dist(rng)); 
            cout << s << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc != 3) {
        cerr << "Usage: ./test_gen <int|strlexi|strlenlexi> <1/2/3/4/5>\n";
        return 1;
    }

    string type = argv[1];
    int test_id = stoi(argv[2]); 

    if (type == "int") {
        gen_int(test_id);
    } 
    else if (type == "strlexi") {
        gen_strlexi(test_id);
    } 
    else if (type == "strlenlexi") {
        gen_strlenlexi(test_id);
    } 
    else {
        cerr << "Invalid benchmark type!\n";
        return 1;
    }

    return 0;
}
