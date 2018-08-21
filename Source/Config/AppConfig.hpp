#ifndef APPCONFIG_HPP
#define APPCONFIG_HPP

#include <string>
#include <cstdint>

#ifdef OTPGEN_GUI
#include <QString>
#include <QSettings>
#include <QSize>
#ifdef OTPGEN_DEBUG
#include <QDebug>
#endif
#endif

class AppConfig final
{
public:
    static const std::string Developer;
    static const std::string Name;
    static const std::string Version;
    static const std::uint16_t VersionMajor;
    static const std::uint16_t VersionMinor;
    static const std::uint32_t PatchLevel;

#ifdef OTPGEN_GUI
    static const QString q(const std::string &str);

    static bool useTheming();

    static const QString titleBarBackground();
    static const QString titleBarForeground();
    static const QString titleBarButtonBackground();
    static const QString titleBarButtonForeground();

    static QSettings *settings();
    static const QString &path();
    static const std::string &database();

    // QSettings keys
    static const QString keyGeometryMainWindow()
    { return "UI/MainWindowGeometry"; }
    static const QString keyGeometryTokenEditor()
    { return "UI/TokenEditorGeometry"; }
    static const QString keyTokenWidgetColumns()
    { return "UI/TokenWidgetColumns"; }
    static const QString keyTokenEditWidgetColumns()
    { return "UI/TokenEditWidgetColumns"; }
    static const QString keyTokenIconsVisible()
    { return "UI/TokenIconsVisible"; }
    static const QString keyTokensVisible()
    { return "UI/TokensVisible"; }

    // Settings defaults
    static const QSize defaultGeometryMainWindow()
    { return QSize(461, 490); }
    static const QSize defaultGeometryTokenEditor()
    { return QSize(957, 290); }
#endif

private:
    AppConfig() = delete;
};

using cfg = AppConfig;

#endif // APPCONFIG_HPP
