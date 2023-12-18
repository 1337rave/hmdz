#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Reservoir {
private:
    std::string name;
    double width;
    double length;
    double maxDepth;

public:
    // Конструктор за замовчуванням
    Reservoir() : name(""), width(0.0), length(0.0), maxDepth(0.0) {}

    // Конструктор з параметрами (explicit)
    explicit Reservoir(const std::string& n, double w, double l, double d)
        : name(n), width(w), length(l), maxDepth(d) {}

    // Деструктор (якщо потрібно)
    ~Reservoir() {
        // Ваш код для деструкції
    }

    // Конструктор копіювання
    Reservoir(const Reservoir& other)
        : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

    // Приблизний обсяг
    double approximateVolume() const {
        return width * length * maxDepth;
    }

    // Площа водної поверхні
    double surfaceArea() const {
        return width * length;
    }

    // Перевірка типу водойми
    bool isSameType(const Reservoir& other) const {
        return (name == other.name);
    }

    // Порівняння площі водної поверхні
    bool operator<(const Reservoir& other) const {
        return surfaceArea() < other.surfaceArea();
    }

    // Копіювання об'єкта
    Reservoir copy() const {
        return *this;
    }

    // Методи set і get (по бажанню)
    void setName(const std::string& n) {
        name = n;
    }

    std::string getName() const {
        return name;
    }

    // Інші методи на ваш розсуд

    // Константна функція-член для відображення даних
    void displayInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Width: " << width << "\n";
        std::cout << "Length: " << length << "\n";
        std::cout << "Max Depth: " << maxDepth << "\n";
        std::cout << "Surface Area: " << surfaceArea() << "\n";
        std::cout << "Approximate Volume: " << approximateVolume() << "\n";
    }
};

std::vector<Reservoir> reservoirArray;

void addObject() {
    std::string name;
    double width, length, maxDepth;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter max depth: ";
    std::cin >> maxDepth;

    Reservoir newReservoir(name, width, length, maxDepth);
    reservoirArray.push_back(newReservoir);
}

void removeObject() {
    int index;
    std::cout << "Enter the index of the reservoir to remove: ";
    std::cin >> index;

    if (index >= 0 && index < reservoirArray.size()) {
        reservoirArray.erase(reservoirArray.begin() + index);
        std::cout << "Reservoir removed successfully.\n";
    }
    else {
        std::cout << "Invalid index.\n";
    }
}

void displayAll() {
    for (size_t i = 0; i < reservoirArray.size(); ++i) {
        std::cout << "Reservoir " << i + 1 << ":\n";
        reservoirArray[i].displayInfo();
        std::cout << "---------------\n";
    }
}

void writeToFileText(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& reservoir : reservoirArray) {
            file << "Name: " << reservoir.getName() << ", Surface Area: " << reservoir.surfaceArea() << "\n";
        }
        file.close();
        std::cout << "Data written to " << filename << " successfully.\n";
    }
    else {
        std::cerr << "Error opening file.\n";
    }
}

void writeToFileBinary(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        for (const auto& reservoir : reservoirArray) {
            file.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
        }
        file.close();
        std::cout << "Data written to " << filename << " successfully.\n";
    }
    else {
        std::cerr << "Error opening file.\n";
    }
}
