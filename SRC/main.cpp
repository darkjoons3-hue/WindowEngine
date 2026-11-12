#include "ZufyUI.h"
#include "ZufyUIWidgets.h"
#include <windows.h>

using namespace ZufyUI;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // 1. Создаем окно (размер 500x300, заголовок WindowEngine)
    Window win;
    if (!win.Create(500, 300, L"WindowEngine Splash")) return 1;

    // 2. Настраиваем корневой контейнер (по центру)
    auto root = win.GetRootColumnBox();
    root->SetSpacing(20);
    // Выравниваем по центру (если ZufyUI поддерживает, иначе по умолчанию)

    // 3. Добавляем текст "WE" (наша заглушка вместо логотипа)
    auto logoLabel = std::make_shared<Label>(L"WE");
    logoLabel->SetFontSize(72); // Крупный шрифт
    // В ZufyUI цвет текста задается через Dsl или свойства, 
    // пока оставим дефолтный, но в будущем сделаем янтарным.

    // 4. Добавляем текст "Loading..."
    auto textLoading = std::make_shared<Label>(L"Загрузка шаблонов...");
    textLoading->SetFontSize(16);

    // 5. Собираем всё вместе
    root->AddChild(logoLabel);
    root->AddChild(textLoading);

    // 6. Запускаем окно
    win.Run();
    return 0;
}
